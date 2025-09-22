/*
author: Prandi Alessandro
date:
es. 6 vettori
testo: Copiare tutti gli elementi pari del vettore V1 caricato da tastiera, nel vettore V2
        dello stesso tipo e dimensione opportuna
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define DIM 100

void chiediVett(int v1[], int n) {
    for(int k = 0; k < n; k++) {
        printf("inserisci l'elemento [%d]: ", k);
        scanf("%d", &v1[k]);
    }
}

void stampaVett(int v[], int n) {
    for(int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

void copia(int v1[], int n1, int v2[], int *n2 ) {
    int j = 0; // j indice di v2
    for(int k = 0; k < n1; k++) {
        if(v1[k] % 2 == 0) {
            v2[j] = v1[k];
            j++;
        }
    }
    *n2 = j; // j rappresenta la posizione libera nel vettore e
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
    int dim1, dim2;
    int vett1[DIM];
    int vett2[DIM];

    printf("inserisci la dimensione del vettore: ");
    dim1 = chiediDimensione(DIM);

    chiediVett(vett1, dim1);

    copia(vett1, dim1, vett2, &dim2);

    stampaVett(vett2, dim2);
return 0;
}
