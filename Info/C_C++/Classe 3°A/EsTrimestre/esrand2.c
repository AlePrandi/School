/*
author: Prandi Alessandro
date: 4/12/2022
es. rand2
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM_MIN 1
#define LIM_MAX 10

int main() {
    srand(time(NULL));
    int n= LIM_MIN + rand()% (LIM_MAX-LIM_MIN+1);
    int tentativo;
    int cont;
    printf("Che numero e' uscito? \n");
    scanf("%d", &tentativo);
    for(cont=0; cont<2; cont++) {
        if(tentativo==n) {
            printf("Hai indovinato!\n");
            printf("Il numero era proprio: %d", n);
            printf("\n");
            cont=3;
        } else
        if(tentativo!=n) {
            printf("Hai sbagliato!\n");
            printf("Inserisci un altro numero: \n");
            scanf("%d",&tentativo);
        }

    }
    if(cont==2) {
        printf("Hai esaurito i tentativi, il numero era : %d", n);
    }
}
