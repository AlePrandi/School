/*
author: Prandi Alessandro
date:21/02/2023
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

void caricaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("inserisci un numero: ");
        scanf("%d", &v[k]);
    }
}

void copiaVett(int v[],int v1[], int n) {
    int j = n - 1;
    for( int k = 0; k < n; k++) {
        v1[j]= v[k];
        j --;
    }
}

void stampaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

int chiediDimensione(int dimMax) {
    int x;
    do {
        printf("inserisci la dimensione minore di [0..%d]", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}

int main() {
    int dim1;
    int vettA[DIM];
    int vettB[DIM];

    printf("inserisci la dimensione del vettore: ");
    dim1 = chiediDimensione(DIM);

    caricaVett(vettA, DIM);

    copiaVett(vettA, vettB, DIM);

    stampaVett(vettB, DIM);
    return 0;
}
