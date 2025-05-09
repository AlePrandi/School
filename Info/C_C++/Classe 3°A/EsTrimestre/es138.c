/*
author: Prandi Alessandro
date: 18/12/2022
es. 138
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 0
#define MAX 100

main() {
    srand(time(NULL));
    int num,tent,n;

    num = MIN + rand() % (MAX + 1 - MIN);
    do {
        printf("inserisci un numero: ");
        scanf("%d", &n);
        if (n > num)
            printf("alto\n\n");
        else if(n < num)
            printf("basso\n\n");
        tent++;
    } while(num != n);
    printf("hai indovinato!\n");
    printf("hai usato %d tentativi", tent);
}
