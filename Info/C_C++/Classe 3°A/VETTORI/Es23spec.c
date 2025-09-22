/*
author: Alessandro Prandi
date: 08/03/2023
es. speculare
testo dire se un vettore è speculare
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 100

int chiediDim(int dim_max) {
    int x;
    do {
        printf("inserire il numero di celle tra [0 e %d]:", dim_max);
        scanf("%d", &x);
    } while (x < 0 || x > dim_max);
    return x;
}

void caricaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("[%d]inserire un numero: ", k);
        scanf("%d", &v[k]);
    }
}

bool ContrSpecVettBool(int v[], int n) {
    int spec = true;
    int j = n-1;
    int k = 0;
    while ((k < n/2) && spec == true) {
        if (v[k] != v[j]) {
            spec = false;
        } else {
            k++;
            j--;
        }
    }
    return spec;
}

int main() {
    int dim;
    int v[DIM];

    dim = chiediDim(DIM);

    caricaVett(v, dim);

    if(ContrSpecVettBool(v, dim) == false)
        printf("il vettore non e speculare");
    else
        printf("il vettore e speculare");
    return 0;
}
