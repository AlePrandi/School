/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

void scambio(int *x, int *y){
    int z;
    z = *x;
    *x = *y;
    *y = z;
}

int chiediDim(int dim_max) {
    int x;
    do {
        printf("Inserisci la dimensione del vettore: ");
        scanf("%d", &x);
    } while(x<0 || x>dim_max);
    return x;
}

void caricaVett(int v[], int dim) {
    int n;
    for(int k=0; k<dim; k++) {
        printf("Inserisci un numero: \n");
        scanf("%d", &n);
        v[k]=n;
    }
}

void invertiVett(int v[], int dim) {
    int x;
    int j=dim-1;
    for(int k=0; k<dim/2; k++, j--) {
       scambio(&v[k], &v[j]);
    }
}

void stampaVett(int v[], int dim) {
    for(int k=0; k<dim; k++) {

        printf("%d ", v[k]);

    }
}
int main() {
    int dim;

    dim=chiediDim(DIM);

    int vett[dim];

    caricaVett(vett,dim);

    invertiVett(vett,dim);

    stampaVett(vett,dim);

    return 0;
}
