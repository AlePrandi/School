/*
author: Prandi Alessandro
date:11/03/2023
es. 30
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include "vettori.h"
#define DIM 100

int carVett(int v[],int v1[],float v2[], int n) {
    for(int k = 0; k < n; k++) {
        printf("[%d]inserisci codice: ", k);
        scanf("%d", &v[k]);
        printf("[%d]inserisci quantita: ", k);
        scanf("%d", &v1[k]);
        printf("[%d]inserisci prezzo singolo: ", k);
        scanf("%f",&v2[k]);
    }
}

void cercaArt(int v[],int v1[], float v2[],int n, int x) {
    int tro,k;
    tro = -1;
    k=0;
    while ((k < n) && (tro == -1)) {
        if(x == v[k]) {
            printf("con questo codice hai %d articoli con un costo singolo di %.2f euro\n", v1[k], v2[k]);
            tro = x;
        } else
            k++;
    }
}

void cerArt0(int v[],int v1[], float v2[],int n) {
    int tro,k;
    tro = -1;
    k=0;
    while ((k < n) && (tro == -1)) {
        if(v1[k] == 0) {
            printf("l'articolo [%d] non ha una quantita\n", k);
            tro = k;
        }

        else
            k++;
    }
}

void somVett(float v[], int n, float *somma) {
    *somma = 0;
    for(int k=0; k<n; k++) {
        *somma = *somma + v[k];
    }
}

void medVett(float v[], int n, float *somma, float *media) {
    if(n != 0) {
        *media = (float) *somma / n;
    }
}

int menu() {
    int scelta;
    printf("0 = Esci\n");
    printf("1 = Carica Articolo \n");
    printf("2 = Cerca Articolo \n");
    printf("3 = Visualizza articoli con valore 0 \n");
    printf("4 = Prezzo medio \n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

int main() {
    int scelta;
    int vett1[DIM],vett2[DIM];
    float vett3[DIM];
    int dim = chiediDim(DIM);
    float somma, media;

    int x;  //valore da cercare
    int tro;  // posizione in cui trovo elemento
    bool caricato = false; //vettore caricato

    do {
        scelta=menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            carVett(vett1,vett2,vett3,dim);
            caricato = true;
            break;
        case 2:
            printf("inserisci il codice che vuoi cercare: ");
            scanf("%d", &x);
            if(!caricato)
                printf("prima caricare il vettore");
            else {
                cercaArt(vett1,vett2,vett3, dim, x);
            }
            break;
        case 3:
            if(!caricato)
                printf("prima caricare il vettore");
            else
                cerArt0(vett1, vett2, vett3, dim);
            break;
        case 4:
            if(!caricato)
                printf("prima caricare il vettore");
            else {
                somVett(vett3, dim, &somma);
                medVett(vett3, dim, &somma, &media);
                printf("il prezzo medio e: %.2f euro\n", media);
            }

            break;
        }
    } while(scelta!=0);

    return 0;
}
