/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 4

void CalcolaSomma(int pari[MAX],int dispari[MAX],int vett[MAX], int *np, int *nd) {
    *np = 0,
    *nd = 0;
    for(int k = 0; k < MAX; k++) {
        if(k % 2 == 0) {
            if(vett[k] % 2 != 0){
                dispari[*nd] = vett[k];
                (*nd)++;
            }
        } else {
            if(vett[k] % 2 == 0){
                pari[*np] = vett[k];
                (*np)++;
            }
        }
    }
}

void CaricaVett(int vett[MAX]){
for(int k = 0; k < MAX; k++){
    printf("inserire un numero[%d]: ",k);
    scanf("%d", &vett[k]);
}
}

void StampaVett(int vett[MAX], int num){
for(int k = 0; k < num; k++){
    printf("%d ", vett[k]);
}
printf("\n");
}

int main() {
    int Pari[MAX], Dispari[MAX],vett[MAX];
    int npari,ndisp;
    CaricaVett(vett);

    CalcolaSomma(Pari,Dispari,vett,&npari,&ndisp);

    printf("Valori pari: \n");
    StampaVett(Pari,npari);
    printf("Valori dispari: \n");
    StampaVett(Dispari,ndisp);
    return 0;
}
