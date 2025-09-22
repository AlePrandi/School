/*
author: Prandi Alessandro
date: 26/02/2023
es. 14
testo
Dato un vettore di 100 numeri casuali con valori compresi tra 0 e 1000, calcolare
la media di tutti i multipli di 3 in esso contenuti.
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 100
#define MIN 0
#define MAX 1000
#define DIV 3

void caricaVett(int v[], int n) {
    srand(time(NULL));
    for (int k = 0; k < n; k++) {
        v[k] = MIN + rand() % (MAX + 1 - MIN);
    }
}

void multipliVett(int v[],float *media, int n) {
    *media = 0;
    int somma = 0;
    int nMult = 0;

    for (int k = 0; k < n; k++) {
        if (v[k] % DIV == 0) {
            somma = somma + v[k];
            nMult++;
        }
    }
    *media = (float) somma / nMult;
}

void stampaVett(float *media) {
    if (*media > 0) {
        printf("La media dei multipli di 3 nel vettore e': %.2f\n", *media);
    } else {
        printf("non ci sono multipli di 3");
    }
}

int main() {

    int vettA[DIM];
    float media;

    caricaVett(vettA, DIM);

    multipliVett(vettA, &media, DIM);

    stampaVett(&media);

return 0;
}
