/*
author: Prandi Alessandro
date: 07/03/2023
es. 25
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define DIM 100
#define MIN -30
#define MAX 30

int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserisci una dimensione compresa tra [0 e %d]: ", dimMax);
        scanf("%d", &x);
    } while(x < 0 || x > dimMax);
    return x;
}

void caricaVettCas(int v[], int n) {
    srand(time(NULL));
    for (int k = 0; k < n; k++) {
        v[k] = MIN + rand() % (MAX + 1 - MIN);
    }
}

bool Contrdiv(int v[], int n) {
    int k = 0;
    int div = true;
    int num = v[k];
    k = 1;
    while ((k < n) && (div == true)) {
        if (v[k] == num){
            div = false;
        }
        else
            k++;
    }
    return div;
}

void stampaVett(int v[], int n) {
    for(int k=0; k<n; k++) {
        printf("%d ", v[k]);
    }
}

int main() {
    int dim;
    dim = chiediDim(DIM);
    int vett[dim];
    bool div;

    caricaVettCas(vett, dim);
    div = Contrdiv(vett, dim);
    stampaVett(vett, dim);
    if (div == false)
        printf("\ni numeri non sono tutti diversi");
    else
        printf("\ni numeri sono tutti diversi");
}
