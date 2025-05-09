/*
author: Prandi Alessandro
date: 15/02/2023
es. esempio Vett
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 3

void caricaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("inserisci l'elemento in posizione [%d]: ", k);
        scanf("%d", &v[k]);
    }
}

void raddoppiaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        v[k]= v[k] * 2;
    }
}

void stampaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

int main() {
    int vett[DIM], uso = 3;// varuabile uso per usarne un certo numero invece del totale

    // carico vettore
    caricaVett(vett, uso);
    // raddoppio
    raddoppiaVett(vett, uso);
    //visualizzo
    stampaVett(vett, uso);

    return 0;
}
