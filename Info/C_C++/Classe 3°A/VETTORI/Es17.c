/*
author: Prandi Alessandro
date: 27/02/2023
es. 17
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100
#define MUL 2

int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserire il numero di celle [0 e %d]:", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);

return x;
}
void caricaVett(int v[], int n) {

    for (int k = 0; k < n; k++) {
        printf("inserire un numero [%d]:", k);
        scanf("%d", &v[k]);
    }
}
void calcoloVett(int v[], int vP[], int vD[], int n, int *n1, int *n2) {
    int j = 0;
    int w = 0;
    for (int k = 0; k < n; k++) {
        if (v[k] % MUL == 0) {
            vP[j] = v[k];
            j++;
        } else {
            vD[w] = v[k];
            w++;
        }
    }
    *n1 = j;
    *n2 = w;
}
void stampaVett(int vP[], int vD[], int n, int n1) {
    printf("vettore pari: \n");
    for (int k = 0; k < n; k++) {
        printf("%d \n", vP[k]);
    }
    printf("vettore dispari: \n");
    for (int j = 0; j < n1; j++) {
        printf("%d \n", vD[j]);
    }
}
int main() {
    int dim, a, b;
    int vett[dim];
    int vettPari[dim];
    int vettDisp[dim];

    dim = chiediDim(DIM);

    caricaVett(vett, dim);

    calcoloVett(vett, vettPari, vettDisp, dim, &a, &b);

    stampaVett(vettPari, vettDisp, a, b);

return 0;
}
