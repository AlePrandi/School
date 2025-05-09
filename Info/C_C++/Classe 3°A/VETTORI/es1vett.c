/*
author: Prandi Alessandro
date: 15/02/2023
es. vettori 1
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void caricaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("inserisci l'elemento in posizione [%d]: ", k);
        scanf("%d", &v[k]);
    }
}

void copiaVett(int v[],int v1[], int n) {
    for( int k = 0; k < n; k++) {
        v1[k]= v[k];
    }
}

void stampaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

int main() {
    int vettA[DIM];
    int vettB[DIM];

    caricaVett(vettA, DIM);

    copiaVett(vettA, vettB, DIM);

    stampaVett(vettB, DIM);
    return 0;
}
