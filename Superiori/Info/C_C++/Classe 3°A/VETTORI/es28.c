/*
author: Alessandro Prandi
date: 14/03/2023
es. 28
testo:
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>
#include <time.h>
#include "vettori.h"
#define DIM 100
#define MIN -100
#define MAX 100

int NonOrdDisg(int v[],int n, int x){
    int tro,k;
    k = 0;
    tro = -1;
    while (k < n && tro == -1){
        if(v[k] == x)
            tro = k;
        else
            k++;
    }
    return tro;
}

void cancellaNum(int v[], int n1, int *n2, int tro){
    int j = 0;
    for(int k = 0; k < n1; k++) {
        if(k != tro){
            v[j] = v[k];
            j++;
        }
    }
    *n2 = j;
}

int main(){
    int vett[DIM];
    int dim1, dim2, x, tro;

    dim1 = chiediDim(DIM);
    caricaVettCasuale(vett, dim1, MIN, MAX);
    stampaVett(vett, dim1);
    printf("\ninserisci il numero che vuoi cercare: ");
    scanf("%d", &x);
    tro = NonOrdDisg(vett, dim1, x);
    if(tro != -1){
        printf("elemento trovato in posizione: %d\n", tro);
        cancellaNum(vett, dim1, &dim2, tro);
        stampaVett(vett, dim2);
    }else{
        printf("elemento non trovato \n");
        stampaVett(vett, dim1);
    }
return 0;
}
