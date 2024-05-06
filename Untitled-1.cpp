// *Campionato di calcio*
// I dati relativi al campionato di calcio sono memorizzati in tre vettori paralleli:

// -Squadre, contenente il nome della squadra;
// Serie, contenente 'A' o 'B';
// -Punti, contenente il numero di punti;

//Scrivi un programma che preveda di visualizzare:
// a) l'elenco delle squadre di serie A nella forma Squadra  Punti;
// b) stampare la serie in cui milita e i punti realizzati; se la squadra non esiste, stampare un messaggio di errore.
// c) costruire e stampare un altro vettore SERIEB contenente solo le squadre di serie B
// d) cercare e stampare il nome della squadra campione di serie A

#include<iostream>
#include<iomanip>
#include<string>

using namespace std;


//Dichiarazione colori
#define RESET   "\033[0m"
#define RED     "\033[31m"    //Retrocesso 
#define GREEN   "\033[32m"   //Conference
#define YELLOW  "\033[33m"  //Campione
#define BLUE    "\033[34m"  //Champions
#define ORANGE  "\033[38;5;208m"  //Europa

//Dichiarazione costanti
const int MAX_SQUADRE=40;
const int PUNTI_MAX=114; // Punteggio massimo per campionato 
const int d=5; //Distanza

//Prototipi
int menu();
int inserimento(string squadre[], char serie[], int punti[],string serieA[],int puntiA[],string serieB[],int puntiB[]);
void ordina(string serieA[],int puntiA[]);
void stamp(string squadre[], char serie[], int punti[]);
void ricerca(string squadre[], char serie[], int punti[], string cercare);
void avanti();


int main(){

    //Dichiarazione Array
    string squadre[MAX_SQUADRE];
    char serie[MAX_SQUADRE];
    int punti[MAX_SQUADRE];

    string serieA[MAX_SQUADRE/2];
    int puntiA[MAX_SQUADRE/2];

    string serieB[MAX_SQUADRE/2];
    int puntiB[MAX_SQUADRE/2];

    //Dichiarazione variabili
    int s,l;
    bool controllo0=false, controllo1=false;

    do{
        system("cls");
        s=menu();

        switch(s){

            case 1:{
                l=inserimento(squadre,serie,punti,serieA,puntiA,serieB,puntiB);
                controllo0=false;
                controllo1=false;
                break;
            }

            case 2:{
                if(controllo0 == false){
                    ordina(serieA,puntiA);
                    controllo0=true;
                }

                cout<<"\t -----Serie A-----\n";
                for(int i=0;i<MAX_SQUADRE/2;i++){

                    if(i==0){
                        cout<<YELLOW<<i+1<<") "<<serieA[i]<<setw( (l-serieA[i].length()) +d)<<puntiA[i]<<RESET<<endl;
                        continue;
                    }
                    else if(i>=1 && i<=3){
                        cout<<BLUE<<i+1<<") "<<serieA[i]<<setw( (l-serieA[i].length()) +d)<<puntiA[i]<<RESET<<endl;
                        continue;
                    }
                    else if(i>=4 && i<=5){
                        cout<<ORANGE<<i+1<<") "<<serieA[i]<<setw( (l-serieA[i].length()) +d)<<puntiA[i]<<RESET<<endl;
                        continue;
                    } 
                    else if(i==6){
                        cout<<GREEN<<i+1<<") "<<serieA[i]<<setw( (l-serieA[i].length()) +d)<<puntiA[i]<<RESET<<endl;
                        continue;
                    }
                    else if(i>=17){
                        cout<<RED<<i+1<<") "<<serieA[i]<<setw( (l-serieA[i].length()) +d)<<puntiA[i]<<RESET<<endl;
                        continue;
                    }
                    else{
                        cout<<i+1<<") "<<serieA[i]<<setw( (l-serieA[i].length()) +d)<<puntiA[i]<<endl;
                    }

                    
                }

                avanti();

                break;
            }

            case 3:{
                if(controllo1 == false){
                    ordina(serieB,puntiB);
                    controllo1=true;
                }

                cout<<"\t -----Serie B-----\n";
                for(int i=0;i<MAX_SQUADRE/2;i++){
                    cout<<i+1<<") "<<serieB[i]<<setw( (l-serieB[i].length()) +d)<<puntiB[i]<<endl;
                }

                avanti();
            
                break;
            }

            case 4:{
                string squadra;

                cout<<"Inserisci la squadra da cercare: ";
                cin.ignore();
                getline(cin,squadra);

                ricerca(squadre,serie,punti,squadra);

                avanti();

                break;

            }

            case 5:{
                if(controllo0 == false){
                    ordina(serieA,puntiA);
                    controllo0=true;
                }

                cout<<YELLOW<<"1) "<<serieA[0]<<"\t"<<puntiA[0]<<RESET<<endl;

                avanti();

                break;

            }


            case 0:{
                cout<<"Arrivederci"<<endl;
                break;
            }

            default:{
                cout<<"Scelta non valida"<<endl;

                avanti();

                break;
            }

        }//switch

    }while(s!=0);

    return 0;
}


int menu(){

    int scelta;

    cout<<"\t -----Menu'-----\n";
    cout<<"1. Inserisci le squade \n";
    cout<<"2. Visualizza le squadre di serie A \n";
    cout<<"3. Visualizza le squadre di serie B \n";
    cout<<"4. Cerca squadra \n";
    cout<<"5. Visualizza la squdra campione d'Italia \n";
    cout<<"0. Esci \n";

    cout<<"\nFai la tua scelta: ";
    cin>>scelta;

    return scelta;
}

int inserimento(string squadre[], char serie[], int punti[],string serieA[],int puntiA[],string serieB[],int puntiB[]){

    int n=0,l=0,max=0;
    bool controllo;

    for(int i=0;i<MAX_SQUADRE;i++){

        cout<<"Inserisci il nome della squadra: ";
        cin.ignore();
        getline(cin ,squadre[i]);

        if(squadre[i].length()>max){
            max=squadre[i].length();
        }

        do{
            cout<<"Inserisci i punti: ";
            cin>>punti[i];

            if(punti[i]<0 || punti[i]>PUNTI_MAX){
                cout<<"Inserisci un punteggio maggiore di 0 e minore di "<<PUNTI_MAX<<endl;
            }

        }while(punti[i]<0 || punti[i]>PUNTI_MAX);


        do{
            controllo=false;
            do{
                cout<<"Inserisci la serie: ";
                cin>>serie[i];

                serie[i]=toupper(serie[i]);

                if(serie[i]!='A' && serie[i]!='B'){
                    cout<<"Inserisci una serie valida"<<endl;
                }

            }while(serie[i]!='A' && serie[i]!='B');

            if(serie[i]=='A'){
                if(n<MAX_SQUADRE/2 ){
                    serieA[n]=squadre[i];
                    puntiA[n]=punti[i];
                    n++;
                }
                else if(n==MAX_SQUADRE/2){
                    cout<<"Non puoi inserire altre squadre in serie A"<<endl;
                    controllo=true;
                }
            }
            else{
                if(l<MAX_SQUADRE/2 ){
                    serieB[l]=squadre[i];
                    puntiB[l]=punti[i];
                    l++;
                }
                else if(l==MAX_SQUADRE/2){
                    cout<<"Non puoi inserire altre squadre in serie B"<<endl;
                    controllo=true;
                }
            }

        }while(controllo==true);

        
        cout<<endl;
    }

    return max;
}


void ordina(string serie[],int punti[]){
    for(int i=0;i<MAX_SQUADRE/2-1;i++){

        for(int j=i+1;j<MAX_SQUADRE/2;j++){

            if(punti[i]<punti[j]){
                swap(punti[i],punti[j]);
                swap(serie[i],serie[j]);
            }
        }
    }
}

void ricerca(string squadre[], char serie[], int punti[], string cercare){
    
    string temp;
    bool controllo=false;

    //Trasformo la stringa in maiuscolo
    for(int i=0;i<cercare.length();i++){
        cercare[i]=toupper(cercare[i]);
    }

    for(int i=0;i<MAX_SQUADRE;i++){
        temp=squadre[i];

        //Trasformo la stringa in maiuscolo
        for(int j=0;j<temp.length();j++){
            temp[j]=toupper(temp[j]);
        }

        if(temp==cercare){
            cout<<squadre[i]<<" - "<<serie[i]<<" - "<<punti[i]<<endl;
            controllo=true;
            break;
        }
    }

    if(controllo==false){
        cout<<"La squadra cercata non esiste"<<endl;
    }

    
}

void avanti(){
    cout<<"\nPremi invio per andare avanti\n";
    cin.ignore();
    cin.get();
}
