/*
author: Alessandro Prandi
date: 05/03/2023
es. 19
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
void FiboVett(int v[], int n){
    for (int k = 0; k < n; k++){
        if (k == 0)
            v[k] = 1;
        else
            if(k == 1)
                v[k] = 1;
            else
                v[k] = v[k - 1] + v[k - 2];
    }
}
void stampaVett(int v[], int n){
    for (int k = 0; k < n; k++){
        printf("%d ", v[k]);
    }
}
int main(){
    int dim;
    dim = chiediDim(DIM);

    int vett[dim];
    FiboVett(vett, dim);
    stampaVett(vett, dim);
return 0;
}
