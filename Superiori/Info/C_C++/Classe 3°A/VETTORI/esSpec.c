/*
author: Prandi Alessandro
date: 08/03/2023
es. Priorità
testo

*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int chiediDim(int dimMax){
    int x;
    do{
    printf("inserire la dimensione [0..%d]: ", dimMax);
    scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}

void caricaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("[%d]inserire un numero: ", k);
        scanf("%d", &v[k]);
    }
}

void scambio(int *x, int *y){
int z;
z = *x;
*x = *y;
*y = z;
}

void selectionSort(int v[],int n) {
int k,kmin,j;
for(k = 0;k < n-1; k++) {
kmin = k;
for(j = k+1; j < n; j++){
if(v[kmin] > v[j]) // confronti
kmin = j;

}
if(kmin != k)
scambio(&v[k], &v[kmin]);
}
return;
}

void stampaVett(int v[], int n) {
    for (int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}

int main(){
int dim;
dim = chiediDim(DIM);
int vett[dim];

caricaVett(vett, dim);
selectionSort(vett, dim);
stampaVett(vett,dim);

return 0;
}
