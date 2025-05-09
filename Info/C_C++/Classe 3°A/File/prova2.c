/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int x;
    int y;
    FILE *fp;
    float divisione;
    int somma = 0;
    int sottrazione;
    int moltiplicazione;
    char c;
    fp=fopen("numeri2.txt", "r");

    if(fp == NULL){
        printf("il file non esiste");
    }else{
        fscanf(fp,"%d",&x);
    fscanf(fp,"%c",&c);
    fscanf(fp,"%d",&y);
    fclose(fp);
    switch(c){
        case '+':
            somma = x + y;
            printf("La somma vale: %d", somma);
            break;
        case '-':
            sottrazione = x - y;
            printf("La differenza vale: %d", sottrazione);
            break;
         case '*':
            moltiplicazione = x * y;
            printf("La moltiplicazione vale: %d", moltiplicazione);
            break;
         case '/':
            divisione = x / y;
            printf("Il quoziente vale: %.2f", divisione);
            break;
    }
    }

}
