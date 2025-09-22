/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 11

void CalcolaSomma(int *pari,int *dispari,int vett[MAX]) {
    *pari = 0;
    *dispari = 0;
    for(int k = 0; k < MAX; k++) {
        if(k % 2 == 0) {
            *pari = *pari + vett[k];
        } else {
            *dispari = *dispari + vett[k];
        }
    }
}

void CaricaVett(int vett[MAX]){
for(int k = 0; k < MAX; k++){
    printf("inserire un numero[%d]: ",k);
    scanf("%d", &vett[k]);
}
}

void StampaSomma(int pari, int dispari){
printf("La somma dei pari e': %d \n",pari);
printf("La somma dei dispari e': %d",dispari);
}

int main() {
    int SommaPari, SommaDispari,vett[MAX];
    CaricaVett(vett);

    CalcolaSomma(&SommaPari,&SommaDispari,vett);

    StampaSomma(SommaPari, SommaDispari);
    return 0;
}
