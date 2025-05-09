/*
author: Prandi Alessandro
date: 9/12/2022
es. G
testo scrivere la funzione che restituisca l'età di una persona, conoscendo il suo anno di nascita
*/
#include <stdio.h>
#include <stdlib.h>
#define ANN_ATT 2023 //istruzioni per il precompilatore

void nascita( int *anno,int *eta){
    *eta = ANN_ATT - *anno;
}

int main() {
    int anno,eta;
    do
    {
     printf("In che anno e' nato?\n");
    scanf("%d", &anno);
    }while (anno > ANN_ATT);
  nascita(&anno, &eta);
  printf("ha %d anni", eta);
  return 0;
}
