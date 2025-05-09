/*
author: Prandi Alessandro
date: 7/12/2022
es. prandi2
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 6
#define VAL 7

int main() {
    srand(time(NULL));
    int budget,dado1,dado2,puntata;
    char risp;

    printf("inserisci il budget iniziale: \n");
    scanf("%d", &budget);
    do {
        printf("inserisci una puntata: \n");
        scanf("%d", &puntata);
        dado1= MIN + rand() % (MAX + 1 - MIN);
        dado2= MIN + rand() % (MAX + 1 - MIN);
        printf("\ndado1: %d dado2: %d\n", dado1,dado2);
        if(dado1 == dado2 || dado1 + dado2 == VAL) {
            budget = budget + puntata;
            printf("hai indovinato\n");
            printf("il tuo budget attuale e: %d\n", budget);
        } else {
            budget = budget - puntata;
            printf("hai sbagliato\n");
            printf("il tuo budget attuale e: %d\n", budget);
        }
        printf("vuoi continuare? ");
        scanf("%s", &risp);

    } while((risp == 's' || risp == 'S') && budget >= 0);
    if(budget <= 0)
        printf("non puoi continuare, hai finito i soldi");



    return 0;
}
