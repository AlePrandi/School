/*
author: Prandi Alessandro
date: 22/02/2023
es. 13
testo:
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int chiediDim(int dim_Max) {
    int dim;
    do {
        printf("Inserisci un valore per la dimensione: ");
        scanf("%d", &dim);
    } while(dim < 0 || dim > dim_Max);
    return dim;
}

void caricaVett(int v[], int dim) {
    for(int k=0; k<dim; k++) {
        printf("Inserisci un numero:\n");
        scanf("%d", &v[k]);
    }
}
void sommaVett(int v1[], int *sommaPari,int *sommaDisp,int dim) {

    *sommaPari = 0;
    *sommaDisp = 0;

    for(int k = 0; k < dim; k++) {
        int x = v1[k];
        if(x % 2 == 0) {
            *sommaPari = *sommaPari + v1[k];
        } else {
            *sommaDisp = *sommaDisp + v1[k];
        }
    }
}
void stampaVett(int *x) {
        printf("%d", *x);
}

int main() {
    int dim;
    int v1[dim];
    int v2[dim];
    int sommaPari;
    int sommaDisp;

    dim = chiediDim(DIM);

    caricaVett(v1,dim);

    sommaVett(v1,&sommaPari,&sommaDisp,dim);

    printf("Vettore pari: \n");
    stampaVett(&sommaPari);

    printf("\nVettore dispari: \n");
    stampaVett(&sommaDisp);

    return 0;
}
