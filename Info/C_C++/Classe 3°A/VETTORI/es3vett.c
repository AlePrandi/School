/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 11

void caricaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("inserisci l'elemento in posizione [%d]: ", k);
        scanf("%d", &v[k]);
    }
}

void tabVett(int v[],int v1[], int n, int tabell) {
    for( int k = 0; k < n; k++) {
        v1[k]= v[k] * tabell;
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
    int tab;

    caricaVett(vettA, DIM);

    printf("\nquale tabellina vuoi fare?  ");
    scanf("%d", &tab);

    tabVett(vettA, vettB, DIM, tab);

    stampaVett(vettB, DIM);

    return 0;
}
