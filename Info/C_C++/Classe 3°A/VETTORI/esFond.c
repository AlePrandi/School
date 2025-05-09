/*
author: Prandi Alessandro
date: 27/02/2023
es. Fond
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#define DIM 100

int DimMax(int n) {
    int x;
    do {
        printf("Inserisci la dimensione del vettore: \n");
        scanf("%d", &x);
    } while(x<0 || x>n);
    return x;
}

void caricaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("[%d]inserire un numero: ", k);
        scanf("%d", &v[k]);
    }
}

bool OrdDisBool(int v[], int n, int x, int *tent) {
    *tent=0;
    int k,tro;
    bool ce=true;
    k = 0;
    tro = -1;
    while((k<n) && (tro == -1) && (ce == false)) {
        *tent=*tent+1;
        if(x==v[k]) {
            tro=k;
        } else {
            if(v[k]>x) {
                ce = false;
            } else
                k++;
        }
    }
    return tro;
}

int main() {
    int x;
    int n_confronti;
    int dim;
    bool tro;
    dim = DimMax(DIM);
    int vett[dim];
    caricaVett(vett, dim);
    printf("Che numero vuoi cercare:");
    scanf("%d", &x);
    tro=OrdDisBool(vett,dim,x,&n_confronti);
    if(tro== true) {
        printf("Numero non trovato! o numeri non in ordine crescente\n");
    } else {
        printf("Numero trovato in posizione %d dopo %d tentativi\n",tro, n_confronti);
    }
}
