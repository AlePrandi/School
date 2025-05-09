/*
author: Prandi Alessandro
date: 18/03/2023
es. 36
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include "vettori.h"
#define DIMVOTO 30
#define DIM 100
#define VOTO 11

int nonOrdnonDisg(int v[], int n, int x){
int nx = 0;
for(int k = 0;k < n; k++){
    if(x == v[k])
        nx++;
    else
        k++;
}
return nx;
}

void CaricaVoto(int v[], int n){
for(int k = 0;k < n; k++){
        do{
         printf("[%d]carica un voto da 0 a 10: ", k);
    scanf("%d", &v[k]);
        }while(v[k] < 0 || v[k] > VOTO);
}
}

void CercaVoto(int votoAlunno[], int voto[], int n){
    for(int j = 0;j < n;j++){
        for(int k = 0;k < VOTO; k++){
        int numvoti=nonOrdnonDisg(voto,VOTO, votoAlunno[j]);
        printf("\nl'alunno %d ha %d voti con valutazione %d", j, numvoti, k);
        }
    }

}

int main(){
int vettVoto[DIMVOTO];
int dim = chiediDim(DIM);
int vettAlunno[dim];

CaricaVoto(vettVoto, DIMVOTO);
CercaVoto(vettAlunno,vettVoto,dim);

return 0;
}
