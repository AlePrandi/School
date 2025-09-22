/*
author: Alessandro Prandi
date:05/03/2023
es. 21
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserire il numero di celle [0..%d]: ", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
}
void caricaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("[%d]inserire un numero: ", k);
        scanf("%d", &v[k]);
    }
}
float Contrcrescc(int v[], int n) {
    int k = 1;
    float cresc = -1;
    int num;
    while ((k < n) && (cresc == -1)) {
        num = v[k-1];
        if(v[k] > num)
            cresc = 1;
        else
            k++;
    }
    return cresc;
}
int main() {
    int dim;
    dim = chiediDim(DIM);

    int vett[dim];
    float contr;
    caricaVett(vett, dim);
    contr = Contrcrescc(vett, dim);

    if (contr == 1)
        printf("i numeri non sono in ordine cresccente");
    else
        printf("i numeri sono in ordine cresccente");
return 0;
}
