/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "GraficaPrandi.h"
#include "vettori.h"
#define DIM 100
#define MIN 0
#define MAX 5

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

void caricaVettCasuali(int v[], int n, int min, int max){
    for (int k = 0; k < n; k++) {
            v[k] = min + rand() % (max + 1 - min);
    }
}

void stampVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        rettangoloPienoColore(v[k], k, 1, 1, '*', 9);
    }
}

int main() {
    srand(time(NULL));
    int dim;
    dim = chiediDim(DIM);
    int vett[dim];

    caricaVettCasuali(vett, dim, MIN, MAX);
    while(1){
        selectionSort(vett, dim);
    }
    stampVett(vett, dim);
    return 0;
}
