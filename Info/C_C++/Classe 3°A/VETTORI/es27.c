/*
author: Prandi Alessandro
date: 07/03/2023
es. 27
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 100

int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserire la dimensione del vettore[0 e %d]:", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}

int NonOrdDisg(int v[],int n, int x) {
    int tro,k;
    tro = -1;
    k=0;
    while ((k < n) && (tro == -1)) {
        if(x == v[k])
            tro = k;
        else
            k++;
    }
    return tro;
}

void caricaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("[%d]inserisci un numero: ",k);
        do {
            scanf("%d", &v[k]);
        } while (NonOrdDisg(v, k, v[k]) != -1);
    }
}

void stampaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("%d ", &v[k]);
    }
}

int main() {
    int dim;
    dim = chiediDim(DIM);
    int vett[dim];

    caricaVett(vett, dim);
    stampaVett(vett, dim);
    return 0;
}
