/*
author: Alessandro Prandi
date: 19/03/2023
es. 34
text: Gli importi delle fatture emesse nel mese di marzo sono organizzati in un vettore.
Dopo aver ordinato in modo crescente il vettore visualizzare l'importo massimo
(l'importo corrisponde all'indice più alto del vettore) e controllare se il valore di
un importo inserito da tastiera è compreso nel vettore (gli importi devono essere
tutti diversi tra loro)(ricerca dicotomica). (programma a menù).
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define NGIORNI 5

void caricaVett(float v[], int n) {
    for(int k=0; k<n; k++) {
        printf("Inserisci l'importo della fattura: \n");
        scanf("%f", &v[k]);
    }
}

int menu() {
    int scelta;
    printf("0 = Esci\n");
    printf("1 = Carica l'importo delle fatture emesse nel mese di marzo \n");
    printf("2 = Visualizza l'importo massimo \n");
    printf("3 = Cerca una fattura tramite il suo importo \n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

void bubbleSort3(float vett[], int n) {
    int k,sup,sca;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (k = 0; k < sup ; k++) {
            if (vett[ k ] > vett[ k+1 ]) {
                scambio(&vett[ k ],&vett[ k+1 ]);
                sca=k ;
            }
        }
        sup=sca ;
    }
}

void scambio(int *a, int* b) {
    int aux;

    aux = *a;
    *a = *b;
    *b = aux;

}

void stampaVett(float v[], int n) {
    printf("L'importo massimo e' %.2f\n", v[n-1]);
}

int ricercaBinariaNonRicorsiva(float v[], int n, int x) {
    int p,u,m,tro; // indice del... p= primo, u=ultimo, m=medio
    p = 0;
    u = n-1;
    tro=-1;
    while((p <= u)&& tro==-1) {
        m = (p+u)/2;
        if(v[m]==x)
            tro=m; // valore x trovato alla posizione m
        else if(v[m] < x)
            p = m+1;
        else // x < v[m]
            u = m-1;
    }
    return tro;
}

void inizGiorni(int v[],int dim){
for(int k = 0;k < dim; k++){
    v[k]= k + 1;
}
}

int main () {
    float vett[NGIORNI];
    int scelta, dim;
    bool caricato = false, ordinato = false;
    do {
        scelta=menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            caricaVett(vett,NGIORNI);
            caricato = true;
            break;
        case 2:
            if (!caricato)
                printf("Prima carica gli importi!!!\n");
            else {
                bubbleSort3(vett, NGIORNI);
                stampaVett(vett, NGIORNI);
                ordinato = true;
            }
            break;
        case 3:
            if (!caricato || !ordinato)
                printf("Prima carica gli importi e ordinali!!!\n");
            else {
                float x;
                printf("Inserisci l'importo della fattura che vuoi cercare: \n");
                scanf("%f", &x);
                if (ricercaBinariaNonRicorsiva(vett, NGIORNI, x) == -1) {
                    printf("Non ho trovato nessuna fattura con importo %.2f\n", x);
                } else {
                    printf("Ho trovato la fattura con importo %.2f\n", x);
                }
            }
            break;
        case 4:
            stampaVett(vett, NGIORNI);
        }
    } while(scelta!=0);

    return 0;
}
