/*
author: Prandi Alessandro
date:21/02/2023
es. 12
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

void caricaVett(float v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("inserisci un numero: ");
        scanf("%f", &v[k]);
    }
}

void sommaVett(float v[],float v1[],float v2[], int n) {

    for( int k = 0; k < n; k++) {
            v2[k] = v1[k] + v[k];
    }
}

void stampaVett(float v[], int n) {
    for( int k = 0; k < n; k++) {
            printf("%.2f ", v[k]);
        }
    }

int chiediDimensione(int dimMax) {
    int x;
    do {
        printf("inserisci la dimensione minore di [0..%d]: ", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}

int main() {
    int dim1;
    float vettA[DIM];
    float vettB[DIM];
    float vettC[DIM];

    printf("inserisci la dimensione del vettore: ");
    dim1 = chiediDimensione(DIM);

    caricaVett(vettA, dim1);
    caricaVett(vettB, dim1);

    sommaVett(vettA, vettB, vettC, dim1);

    stampaVett(vettC, dim1);
    return 0;
}
