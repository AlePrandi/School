/*
author: Alessandro Prandi
date: 07/03/2023
es. 26
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserire la dimensione del vettore[0 e %d]:", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}

void caricaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("[%d]inserire un numero in ordine crescente: ", k);
        scanf("%d", &v[k]);
        while(k > 0 && v[k] < v[k - 1]) {
            printf("[%d]valore non valido, reinserire: ", k);
            scanf("%d", &v[k]);
        }
    }
}

void stampaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("%d ", v[k]);
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
