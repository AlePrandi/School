/*
author: Prandi Alessandro
date: 21/02/2023
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 10

void caricaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("inserisci l'elemento [%d]: ", k);
        scanf("%d", &v[k]);
    }
}

void copiaVett(int v[],int v1[], int n, int *n1) {
    int j = 0;
    for( int k = 0; k < n; k++) {
        v1[j]= v[k];
        j++;
        k++;
    }
    *n1 = j;
}

void stampaVett(int v[], int n) {
    for( int k = 0; k < n; k ++) {
        printf("%d ", v[k]);
    }
}

int main() {
    int vettA[DIM];
    int vettB[DIM];
    int n1 = 0;

    caricaVett(vettA, DIM);

    copiaVett(vettA, vettB, DIM, &n1);

    stampaVett(vettB, n1);
    return 0;
}
