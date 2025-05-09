/*
author: Prandi Alessandro
date: 27/02/2023
es. Menu
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define DIM 100

int ScegliDim(int n) {
    int x;
    do {
        printf("Inserisci la dimensione del vettore: \n");
        scanf("%d", &x);
    } while(x<0 || x>n);
    return x;
}

void caricaVett(int v[], int n) {
    int x;
    for(int k=0; k<n; k++) {
        printf("Inserisci un numero: \n");
        scanf("%d", &x);
        v[k]=x;
    }
}

void caricaVettCasuali(int v[], int n, int lim_min, int lim_max) {
    srand(time(NULL));

    for(int k=0; k<n; k++) {
        v[k] = lim_min + rand() % (lim_max-lim_min+1);
    }
}

int menu() {
    int scelta;
    printf("0 = Esci\n");
    printf("1 = Carica Vett  \n");
    printf("2 = Carica Vett casuale \n");
    printf("3 = Stampa Vett \n");
    printf("4 = Ricerca Non ordinati disgiunti \n");
    printf("5 = Ricerca Non ordinati disgiunti booleano \n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

int NoDis(int v[], int n, int x, int *tent) {
    int tro,k;

    *tent=0;
    tro=-1;
    k=0;
    int tentat=0;
    while((k<n) && (tro==-1)) {
        *tent=*tent+1;
        if(x == v[k]) {
            tro = k;
        } else {
            k++;
        }
    }
    return tro;
}

bool NoDisBool(int v[], int n, int x, int *tent) {
    *tent=0;
    int k=0;
    bool tro=false;
    while(k<n && !tro) {
        *tent=*tent+1;
        if(x==v[k]) {
            tro=true;
        } else {
            k++;
        }
    }
    return tro;

}

void stampaVett(int v[], int n) {
    for(int k=0; k<n; k++) {
        printf("%d \t", v[k]);
    }
}


int main() {
    int scelta;
    int vett[DIM];
    int dim = 0;

    int x;  //valore da cercare
    int n_confronti; // numero di confronti
    int tro;  // posizione in cui trovo elemento
    bool caricato = false; //vettore caricato

    do {
        scelta=menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            dim = ScegliDim(DIM);
            caricaVett(vett,dim);
            caricato = true;
            break;
        case 2:
            dim = ScegliDim(DIM);
            int lim_min;
            int lim_max;
            printf("Inserisci il valore minimo: ");
            scanf("%d", &lim_min);
            printf("Inserisci il valore massimo: ");
            scanf("%d", &lim_max);
            caricaVettCasuali(vett,dim,lim_min,lim_max);
            caricato = true;
            break;
        case 3:
            stampaVett(vett,dim);
            printf("\n");
            break;
        case 4:
            if (!caricato)
                printf("prima caricare il vettore!\n");
            else {
                printf("Che numero vuoi cercare:");
                scanf("%d", &x);
                tro=NoDis(vett,dim,x,&n_confronti);
                if(tro==-1) {
                    printf("Numero non trovato! \n");
                } else {
                    printf("Numero trovato in posizione %d dopo %d tentativi\n",
                           tro, n_confronti);
                }
            }
            break;
        case 5:
            if (!caricato)
                printf("prima caricare il vettore!\n");
            else {
                printf("Che numero vuoi cercare:");
                scanf("%d", &x);
                if(NoDisBool(vett,dim,x,&n_confronti)==true) {
                    printf("Numero trovato dopo %d tentativi \n", n_confronti);
                } else {
                    printf("Numero non trovato!\n");
                }
            }
            break;
        }
    } while(scelta!=0);
}
