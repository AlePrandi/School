/*
author: Alessandro Prandi
date:
es. Menu
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>

#define N_MIN -50
#define N_MAX 50
#define MIN 0

int intervallo = abs(N_MIN) + abs(N_MAX);
bool ordinato, disgiunto;   //variabili che verificano se il vettore � disgiunto o ordinato

//prototipo della procedura che termina l'eseczione
void tasto0();

//prototipo della procedura che popola il vettore
void tasto1(int vett[], int dim);

//prototipo della procedura che esegue una verifica per sapere se il vettore è rodinato
void tasto2(int vett[], int dim);

//prototipo della funzione che esegue una verifica sul vettore per capire se è disgiunto o no
void tasto3(int vett[], int dim);

//prototipo della procedura che verifica se il vettore è ordinato ed esegue una ricerac binaria
void tasto4(int vett[], int dim);

//prototipo della procedura che verifica, se il vettore non è gia ordiato e disgiunto ed esegue ricerche sequenziali per ogni tipo di vettore
void tasto5(int vett[], int dim);

//prototipo della procedura che stampa il vettore
void tasto6(int vett[], int dim);

//prototipo della procedura che esegue ordinamento selection sort se il vettore non è già ordinato
void tasto7(int vett[], int dim);

//prototipo della procdura che esegue ordinamento con bubble sort se il vettore non è già ordinato
void tasto8(int vett[], int dim);

//prototipo della procedura che esegue l'ordinamento con quick sort se il vettore non è già ordinato
void tasto9(int vett[], int dim);


//Scrivere una funzione (RicercaSeqNonOrdDisg) che,
//dato un vettore non ordinato di elementi disgiunti,
//la dimensione del vettore e un intero X, attraverso
//una ricerca sequenziale restituisce la posizione
//dell�elemento X se lo trova, -1 in caso contrario.
int RicercaSeqNonOrdDisg(int vett[], int dim, int x);

//Scrivere una funzione (RicercaSeqOrdDisg) che,
//dato un vettore ordinato di elementi disgiunti,
//la dimensione del vettore e un intero X, attraverso
//una ricerca sequenziale restituisce la posizione
//dell�elemento X se lo trova, -1 in caso contrario.
int RicercaSeqOrdDisg(int vett[], int dim, int x);

//Scrivere una funzione (RicercaSeqNonOrdNonDisg) che,
//dato un vettore non ordinato di elementi non disgiunti,
//la dimensione del vettore e un intero X, attraverso una
//ricerca sequenziale restituisce il numero di occorrenze di X trovate.
int RicercaSeqNonOrdNonDisg(int vett[], int dim, int x);

//Scrivere una funzione (RicercaSeqOrdNonDisg) che, dato un
//vettore ordinato di elementi non disgiunti, la dimensione
//del vettore e un intero X attraverso una ricerca sequenziale
//restituisce il numero di occorrenze di X trovate.
int RicercaSeqOrdNonDisg(int vett[], int dim, int x);

//Scrivere una funzione (RicercaBinaria) che, dato un vettore
//ordinato di elementi, la dimensione del vettore e un intero X,
//attraverso una ricerca binaria restituisce la posizione dell'elemento
//X se lo trova, -1 in caso contrario.
int RicercaBinaria(int vett[], int dim, int x);

//Scrivere una procedura (PopolaVettore) che dato un vettore e la
//sua dimensione lo popola con valori casuali compresi tra -50 e +50.
void PopolaVettore(int vett[], int dim);

//Scrivere una procedura (PopolaVettoreCrescente) che dato un vettore
//e la sua dimensione lo popola con valori crescenti (controllare ad
//ogni inserimento che il valore inserito sia >= del precedente se no si fa reinserire).
void PopolaVettoreCrescente(int vett[], int dim);

//Scrivere una procedura (PopolaVettoreDisgiunti) che dato un vettore e la
//sua dimensione lo popola con valori disgiunti (controllare ad ogni inserimento
//che il valore inserito non sia gia' presente  se no si fa reinserire)
void PopolaVettoreDisgiunti(int vett[], int dim);

//Scrivere una funzione (VettoreOrdinatoCrescente) che dato un vettore e la sua dimensione
//restituisce true se il vettore e' ordinato in ordine crescente false altrimenti.
bool VettoreOrdinatoCrescente(int vett[], int dim);

//Scrivere una procedura (StampaVettore) che dato un vettore e la sua dimensione lo stampa.
void StampaVettore(int vett[], int dim);

//Scrivere una funzione (VettoreDisgiunto) che dato un vettore e la sua dimensione
//restituisce true se il vettore contiene elementi disgiunti (non contiene ripetizioni) false altrimenti.
bool VettoreDisgiunto(int vett[], int dim);


//procedura per eseguire ordinamento di un vettore dato in input con algoritmo del bubble sort
void ordinamentoBubble(int vett[], int dim);

//procedura per eseguire ordinamento di un vettore dato in input con algoritmo del selection sort
void ordinamentoSelection(int vett[], int dim);

//procedura che scambia i valori di due puntatori a e b tra di loro
void scambia(int *a, int *b);

//dichiarazione della procedura che ordina il vettore con algoritmo del quick sort
void ordinamentoQuick(int vett[], int dim, int inf);

int main()
{
    disgiunto = ordinato = false;   //pongo le variabili ad uno stato iniziale false perch� non so com'� caricato il vettore
    int n, dim; //dichiaro due variabili una per il numero inserito per il menù e uno per la dimensione del vettore, in quest'ordine
    printf("inserisci il numero di valori che puo' avere il vettore:     ");
    scanf("%d", &dim);
    int vett[dim];  //dichiaro il vettore con dimensione quella inserita dall'utente
    do
    {
        printf("inserisci la funzione che vuoi eseguire(inserendo il numero associato): \n");
        printf("    0 = esci\n");
        printf("    1 = carica il vettore con valori casuali da -50 a 50\n");
        printf("    2 = carica il vettore con valori crescenti\n");
        printf("    3 = carica il vettore con valori disgiunti\n");
        printf("    4 = ricerca un valore X dato in input con la ricerca binaria\n");
        printf("    5 = ricerca un valore X dato in input con la ricerca sequenziale\n");
        printf("    6 = stampa il vettore\n");
        printf("    7 = ordina il vettore con selection Short\n");
        printf("    8 = ordina il vettore con il Bubble Short\n");
        printf("    9 = ordina il vettore con il Quick Sort\n");
        printf("inserisci il numero:    ");
        scanf("%d", &n);    //leggo il valore inserito dall'utete per il menu'
        switch(n) //seleziono il case secondo la voce del menu'
        {
            case 0:
                //richiamo la procedura che esegue il tasto 0
                tasto0();
                break;
            case 1:
                //richiamo la procedura per il tasto 1
                tasto1(vett, dim);
                break;
            case 2:
                //richiamo la procedura per il tasto 2
                tasto2(vett, dim);
                break;
            case 3:
                //richiamo la procedura per il tasto 3
                tasto3(vett, dim);
                break;
            case 4:
                //richiamo la procedura per il tasto 4
                tasto4(vett, dim);
                break;
            case 5:
                //richiamo la procedura per il tasto 5
                tasto5(vett, dim);
                break;
            case 6:
                //richiamo la procedura per il tasto 6
                tasto6(vett, dim);
                break;
            case 7:
                //richiamo la procedura per il tasto 7
                tasto7(vett, dim);
                break;
            case 8:
                //richiamo la procedura per il tasto 8
                tasto8(vett, dim);
                break;
            case 9:
                //richiamo la procedura per il tasto 9
                tasto9(vett, dim);
                break;
            default:    //entro in questo se il valore inserito non è compreso nel menù
                printf("hai inserito un numero non compreso nel menu riprova");
        }
    }while(n!=0);   //ciclo fino a quando non inserisco 0 che � la condizione per uscire
}

//dichiarazione della procedura che termina l'eseczione
void tasto0()
{
    printf("stai uscendo");
        //verificado con lo 0 la condizione di uscita dal ciclo while, stampo l'uscita dal menù e finisco l'esecuzione
}

//dichiarazione della procedura che popola il vettore
void tasto1(int vett[], int dim)
{
    //richiamo la funzione popola vettore che popola un vettore dato in input con valori da -50 a 50
    PopolaVettore(vett, dim);
}

//dichiarazione della procedura che esegue una verifica per sapere se il vettore è rodinato
void tasto2(int vett[], int dim)
{
    //richiamo la procedura che fa popolare un vettore con valori in modo ordinato crescente
    PopolaVettoreCrescente(vett, dim);

    //pongo che il vettore è ordinato e che non è disgiunto
    ordinato= true;
    disgiunto= false;
}

//dichiarazione della funzione che esegue una verifica sul vettore per capire se è disgiunto o no
void  tasto3(int vett[], int dim)
{
    //richiamo la procedura per popolare il vettore con valori disgiunti
    PopolaVettoreDisgiunti(vett, dim);

    //pongo che il vettore è disgiunto e che non è ordinato
    disgiunto = true;
    ordinato = false;
}

//dichiarazione della procedura che verifica se il vettore è ordinato ed esegue una ricerac binaria
void tasto4( int vett[], int dim)
{
    int x, pos;
    //verifico che il vettore sia ordinato, se non è gia detto dalla variabile ordinato
    if (!ordinato)
    {
        ordinato = VettoreOrdinatoCrescente(vett, dim);
    }

    //se il vettore è ordinato allora si richiede all'utente un valore e si esegue la ricerca binaria
    if(ordinato)
    {
        //richiedo all'utente un'valore
        printf("inserisci il valore da ricercare:   ");
        scanf("%d", &x);

        //eseguo la ricerca binaria
        pos = RicercaBinaria(vett, dim, x);

        //stampo la posizione in cui si trova il valore cercato all'interno del vettore
        printf("la posizione e' %d", pos);
    }
    else
    {
        //se il vettore non è ordinato stampa un'errore che dice di ordinarlo o di reinserirlo
        printf("il vettore non e' ordinato, riscrivi il vettore e ritenta o utilizza le funzioni 6 o 7");
    }
}

//dichiarazione della procedura che verifica, se il vettore non è gia ordiato e disgiunto ed esegue ricerche sequenziali per ogni tipo di vettore
void tasto5(int vett[], int dim)
{
    //dichiaro le variabili x per l'inserimento dell'elemento da troavre nel vettore, occorrenze che è il numero di volte
    //che l'elemento è stato trovato all'interno del vettore e pos che è la posizione del valore all'interno del vettore
    //le ultime non sono obbligatorie entrambe, ne basta una nella quale si salva il valore che ritorna ogni funzione
    int x, occorrenze, pos;

    //chiedo all'utente il valore per il quale verificare il vettore
    printf("inserisci il numero per il quale verificare il vettore:     ");
    scanf("%d", &x);

    //se la variabile ordinato e la variabile disgiunto non sono true allora viene eseguita la verifica
    //che rimanda true o false se sono ordinati e disgiunti
    if(!ordinato)
        ordinato = VettoreOrdinatoCrescente(vett, dim);
    if (!disgiunto)
        disgiunto = VettoreDisgiunto(vett, dim);

    //dopo aver determinato che vettore è sapendo se è ordinato e se è disgiunto
    //si esegue la ricerca più adatta
    if (ordinato)
    {
        if (disgiunto)
        {
            //si esegue questa ricerca se il vettore è ordinato e disgiunto e richiamo la relativa funzione
            pos = RicercaSeqOrdDisg(vett, dim, x);

            //stampo il valore rimandato dalla funzione
            printf("la posizione in cui %d e' stato trovato e':     ", x, pos);
        }
        else
        {
            //si esegue questa ricerca se il vettore è ordinato ma non disgiunto e richiamo la relativa funzione
            occorrenze = RicercaSeqOrdNonDisg(vett, dim, x);

            //stampo il numero di occorrenze rimandato dalla funzione se non c'è viene rimandato e stampato -1
            printf("il numero di occorrenze che il valore %d ha all'interno del vettore � di %d", x, occorrenze);
        }
    }
    else
    {
        if(disgiunto)
        {
            //si esegue questa ricerca se il vettore non è ordinato ma è disgiunto e richiamo la relativa funzione
            pos = RicercaSeqNonOrdDisg(vett, dim, x);

            //stampo la posizione del valore per il quale verificare il vettore all'interno di questo, se non c'è rimanda -1
            printf("la posizione in cui %d e' stato trovato e':     ", x, pos);
        }
        else
        {
            //si esegue questa ricerca se il vettore non è ordinato e nemmeno disgiunto e richiamo la relativa funzione
            occorrenze = RicercaSeqNonOrdNonDisg(vett, dim, x);

            //stampo il numero di occorrenze rimandato dalla funzione
            printf("il numero di occorrenze che il valore %d ha all'interno del vettore � di %d", x, occorrenze);
        }
    }
}

// dichiarazione della procedura che stampa il vettore
void tasto6( int vett[], int dim)
{
    //richiamo la procedura che stampa il vettore
    printf("stai per visualizzare il vettore\n");
    StampaVettore(vett, dim);
}

//dichiarazione della procedura che esegue ordinamento selection sort se il vettore non è già ordinato
void tasto7(int vett[], int dim)
{
    //verifico se il vettore è già ordinato
    if(ordinato)
    {
        printf("il tuo vettore è già ordinato");
    }
    //se non è ordinato eseguo l'ordinamento con selection short richiamando la procedura che lo esegue
    else
    {
        printf("ora ordino eseguendo l'ordinamento selection Short");
        ordinamentoSelection(vett, dim);
    }
}

//dichiarazione della procdura che esegue ordinamento con bubble sort se il vettore non è già ordinato
void tasto8(int vett[], int dim)
{
    //verifico che  il vettore sia ordinato e se lo è dico all'utente che è ordinato
    if(ordinato)
    {
        printf("il tuo vettore è già ordinato");
    }
    //se non è ordinato allora lo ordino richiamando la procedura che esegue l'ordinamento bubble sort
    else
    {
        ordinamentoBubble(vett, dim);
        printf("ora ordino eseguendo l'ordinamento bubble Short ");
    }
}

//dichiarazione della procedura che esegue l'ordinamento con quick sort se il vettore non è già ordinato
void tasto9(int vett[], int dim)
{
    //verifico che  il vettore sia ordinato e se lo è dico all'utente che è già ordinato e non serve eseguire questa istruzione
    if(ordinato)
    {
        printf("il tuo vettore è già ordinato");
    }
    //se non è ordinato allora lo ordino richiamando la procedura che esegue l'ordinamento quick sort
    else
    {
        ordinamentoQuick(vett, dim, MIN);
        printf("ora ordino eseguendo l'ordinamento quick Short ");
    }
}

//Scrivere una funzione (RicercaSeqNonOrdDisg) che,
//dato un vettore non ordinato di elementi disgiunti,
//la dimensione del vettore e un intero X, attraverso
//una ricerca sequenziale restituisce la posizione
//dell�elemento X se lo trova, -1 in caso contrario.
int RicercaSeqNonOrdDisg(int vett[], int dim, int x)
{
    //dichiaro due variabili, una per la posizione, l'altra per il contatore
    int pos, cont;
    pos = -1; //la posizione la inizializzo a -1 in modo tale che se non venga trovato il valore all'interno del vettore allora restituisca -1 quindi cella del vettore inesistente
    cont = 0;
    while((cont < dim) && (pos == -1)) //ciclo fino a quando il contatore è minore di dim o fino a quando la posizione rimane -1 quindi se il valore viene trovato all'interno del vettore il ciclo termina
    {
        //verifico se trovo il valore x nella cella vett[cont] se si cambio pos e termino il ciclo se no incremento il cont
        if(x == vett[cont])
        {
           pos=cont;
        }
        else
        {
            cont++;
        }
    }
    //ritorno la posizione in cui si trova il valore
    return pos;
}

//Scrivere una funzione (RicercaSeqOrdDisg) che,
//dato un vettore ordinato di elementi disgiunti,
//la dimensione del vettore e un intero X, attraverso
//una ricerca sequenziale restituisce la posizione
//dell�elemento X se lo trova, -1 in caso contrario.
int RicercaSeqOrdDisg(int vett[], int dim, int x)
{
    //dichiaro una variabile pos per la posizione del valore nel vettore, che inizializzo a -1 cella del vettore inesistente e la variabile cont per il contatore
    //della posizione che inizializzo a 0 per la prima cella del vettore
    int pos, cont;
    //dichiaro una variabile booleana che inizializzo a true e cambia il suo stato se si riscontra che il valore della cella sia maggiore di quello da ricercare
    bool continua;
    pos = -1;
    cont = 0;
    continua = true;
    while ((cont<dim) && (pos == -1) && (continua == true)) //eseguo un cilo fino a quando non suero la dimensione o fino a quando pos non cambia o fino a quando cotinua non rimane true
    {
        //verifico se la cella vett[cont] contiene il valore di x, se si allora salvo la posizione cont del valore
        if(x == vett[cont])
        {
            pos = cont;
        }
        else
        {
            //se la cella vett[cont] non contiene il valore di x verifico che il valore non sia maggiore di x
            if(vett[cont] > x)
            {
                continua = false;   //se il valore della cella è maggiore di x cambio il valore di continua perchè essendo un vettore ordinato in modo crescente e
                                    //disgiunto so di per certo che i valori successivi saranno maggiorni e quindi non devo nemmeno verificarli
            }
            else
            {
                cont++; //se invece la condizione non è verificata incremento il cont
            }
        }
    }
    //restituisco la posizione del valore all'interno del vettore
    return pos;
}

//Scrivere una funzione (RicercaSeqNonOrdNonDisg) che,
//dato un vettore non ordinato di elementi non disgiunti,
//la dimensione del vettore e un intero X, attraverso una
//ricerca sequenziale restituisce il numero di occorrenze di X trovate.
int RicercaSeqNonOrdNonDisg(int vett[], int dim, int x)
{
    //dichiaro una variabile che inizializzo a 0 per il numero di occorrenze del valore nel vettore
    int numOcc = 0;
    for (int cont=0; cont<dim; cont++)  //scorro tutto il vettore
    {
        if(x == vett[cont]) //se il  valore del vettore è uguale alla x il numero di occorrenze aumenta
        {
            numOcc++;
        }
    }

    //ritorno il numero di occorrenze del valore nel vettore
    return numOcc;
}

//Scrivere una funzione (RicercaSeqOrdNonDisg) che, dato un
//vettore ordinato di elementi non disgiunti, la dimensione
//del vettore e un intero X attraverso una ricerca sequenziale
//restituisce il numero di occorrenze di X trovate.
int RicercaSeqOrdNonDisg(int vett[], int dim, int x)
{
    //dichiaro due variabili, una per il numero di occorrenze del valore x all'interno del vettore e il cont per il contatore della posizione
    int numOcc, cont;
    numOcc = cont = 0; //entrambi li inizializzo a 0 perchè non ci sono ancora ricorrenze e parto dalla posizione zero del vettore
    bool continua;  //dochiaro una variabile booleana continua che è true fino a quando il valore della cella non supera x
    continua = true;    //inizializzo il valore della variabile a true per eseguire il ciclo almeno una volta
    while (cont<dim && continua)    //eseguo un ciclo che continua fino a qunado cont è minore di dim e continua è true
    {
        if(x == vett[cont])
        {
            numOcc++;   //se il valore della cella vett[cont] è == al valore di x incremento il numero di occorrenze
        }
        else
        {
            if(vett[cont] > x)
            {
                continua = false;   //se il valore di x è minore del valore contentuto nel vettore cordinato in
                                    //modo cerscente allora vuol dire che x non potrà trovarsi all'interno del vettore
            }
        }
        cont++; //
    }
    return numOcc;
}

//Scrivere una funzione (RicercaBinaria) che, dato un vettore
//ordinato di elementi, la dimensione del vettore e un intero X,
//attraverso una ricerca binaria restituisce la posizione dell�elemento
//X se lo trova, -1 in caso contrario.
int RicercaBinaria(int vett[], int dim, int x)
{
    int p, u, m, posizione;
    p = 0;
    u = dim - 1;
    posizione = -1;
    while((p <= u) && posizione==-1)
    {
        m = (p+u)/2;
        if (vett[m] == x)
        {
            posizione = m;
        }
        if (vett[m] < x)
        {
            p = m + 1;
        }
        else
        {
            u = m - 1;
        }
    }
    return posizione;
}

//Scrivere una procedura (PopolaVettore) che dato un vettore e la
//sua dimensione lo popola con valori casuali compresi tra -50 e +50.
void PopolaVettore(int vett[], int dim)
{
    srand(time(0));
    for(int cont=0; cont<dim; cont++)
    {
        vett[cont]= N_MIN+rand()%intervallo;
    }
}


//Scrivere una procedura (PopolaVettoreCrescente) che dato un vettore
//e la sua dimensione lo popola con valori crescenti (controllare ad
//ogni inserimento che il valore inserito sia >= del precedente se no si fa reinserire).
void PopolaVettoreCrescente(int vett[], int dim)
{
    int n;
    for(int cont=0; cont<dim; cont++)
    {
        printf("inserisci un numero:    ");
        scanf("%d", &n);
        vett[cont] = n;
        int Cont = 0;
        while(n<vett[cont-1] && cont!=0)
        {
            if (Cont==4)
            {
                printf("il valore precedente � %d ", vett[cont-1]);
            }
            printf("hai inserito un numero minore del prevedente, inseriscine un'altro:   ");
            scanf("%d", &n);
            vett[cont] = n;
            Cont++;
        }
    }
}

//Scrivere una procedura (PopolaVettoreDisgiunti) che dato un vettore e la
//sua dimensione lo popola con valori disgiunti (controllare ad ogni inserimento
//che il valore inserito non sia gi� presente  se no si fa reinserire)
void PopolaVettoreDisgiunti(int vett[], int dim)
{
    int n;
    for(int cont=0; cont<dim; cont++)
    {
        bool disgiunto = true;

        printf("inserisci un numero che non sia gi� stato inserito precendentemente:    ");
        scanf("%d", &n);
        vett[cont] = n;
        while(disgiunto)
        {
            if (cont!=0)
            {
                for(int cont1=0; cont1<cont; cont1++)
                {
                    if (vett[cont] == vett[cont1])
                    {
                        disgiunto = false;
                    }
                }
            }
            if (!disgiunto)
            {
                printf("hai inserito un numero che avevi gia' messo, risprova:     ");
                scanf("%d", &n);
            }
            else
            {
                disgiunto = !disgiunto;
            }

        }
    }
}

//Scrivere una funzione (VettoreOrdinatoCrescente) che dato un vettore e la sua dimensione
//restituisce true se il vettore � ordinato in ordine crescente false altrimenti.
bool VettoreOrdinatoCrescente(int vett[], int dim)
{
    bool stato = false;
    for(int cont=1; cont<dim; cont++)
    {
        if (vett[cont]<vett[cont-1])
        {
            return stato;
        }
        if (cont == dim)
        {
            return (!stato);
        }
    }
}

//Scrivere una procedura (StampaVettore) che dato un vettore e la sua dimensione lo stampa.
void StampaVettore(int vett[], int dim)
{
    for(int cont=0; cont<dim; cont++)
    {
        printf("%d\n", vett[cont]);
    }
}

//Scrivere una funzione (VettoreDisgiunto) che dato un vettore e la sua dimensione
//restituisce true se il vettore contiene elementi disgiunti (non contiene ripetizioni) false altrimenti.
bool VettoreDisgiunto(int vett[], int dim)
{
    bool disgiunti = true;
    for(int cont=0; cont<dim; cont++)
    {
        for(int cont1=0; cont1<dim; cont1++)
        {
            if(cont == cont1)
            {
                continue;
            }

            if (vett[cont] == vett[cont1])
            {
                disgiunti = false;
                break;
            }
        }
    }
    return disgiunti;
}

//date due variabili a e b scambio il loro valore, con un passaggio per riferimento
void scambia(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

void ordinamentoSelection(int vett[], int dim)
{
    for(int cont=0; cont<dim-1;cont++)
    {
        for (int cont1 = cont+1; cont1<dim; cont1++)
        {
            if (vett[cont]>vett[cont1])
            {
                scambia(&vett[cont], &vett[cont1]);
            }
        }
    }
}

void ordinamentoBubble(int vett[], int dim)
{
    int superiore, c;
    int sup = dim -1;
    bool sca = true;
    while((superiore>0)&& sca)
    {
        sca = false;
        for (int cont = 0; cont < dim; cont++)
        {
            if(vett[cont]>vett[cont+1])
            {
                scambia(&vett[cont], &vett[cont+1]);
                sca = true;
            }
        }
        sup--;
    }
}

//dichiarazione della procedura che ordina il vettore con algoritmo del quick sort
void ordinamentoQuick(int vett[], int dim, int inf)
{
    int pivot = vett[(inf + dim)/2];
    int i = inf;
    int j = dim;
    while(i <= j)
    {
        while(vett[i] < pivot) i++; //verifica che le celle del vettore prima della cella centrale siano minori della cella centrale del vettore
        while(vett[j] > pivot) j--; //verifica che le celle del vettore dopo a quella centrale siano maggiori della cella centrale del vettore
        //entrambi si fermano sicuramente sulla cella centrale

        if (i < j) //controllo di non essere nella stessa cella, quindi pivot ed eseguo
        {
            scambia(&vett[i], &vett[j]);//scambio il valore delle due celle del vettore richiamando la procedura che scambia
        }

        if (i <= j) //con < continuo il ciclo, con == termino il ciclo
        {
            i++;
            j--;
        }
    }
    if (inf < j) ordinamentoQuick(vett, inf, j);
    if(i < dim) ordinamentoQuick(vett, i, dim);
}
