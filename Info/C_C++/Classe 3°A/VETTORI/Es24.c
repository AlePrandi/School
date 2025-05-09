/*
author: Alessandro Prandi
date: 05/03/2023
es. 24
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 100

int chiediDim(int dimMax){
    int x;
    do{
    printf("inserire la dimensione [0..%d]: ", dimMax);
    scanf("%d", &x);
    } while (x < 0 || x > dimMax);
    return x;
}
void caricaVett(int v[], int n){
    for (int k = 0; k < n; k++){
        printf("[%d]inserire un numero: ", k);
        scanf("%d", &v[k]);
    }
}
bool ContrUguali(int v[], int n){
    int k = 0;
    int uguali = true;
    int num;
    num = v[k];
    while ((k < n) && (uguali == true)){
        if (v[k] != num)
            uguali = false;
        else
            k++;
    }
    return uguali;
}
int main(){
    int dim;
    dim = chiediDim(DIM);
    int vett[dim];
    bool uguali;

    caricaVett(vett, dim);
    uguali = ContrUguali(vett, dim);
    if (uguali == false)
        printf("i numeri inseriti non sono tutti uguali");
    else
        printf("i numeri inseriti sono tutti uguali");
return 0;
}
