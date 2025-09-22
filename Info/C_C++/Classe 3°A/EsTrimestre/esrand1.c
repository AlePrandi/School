/*
author: Prandi Alessandro
date: 30/11/2022
es.rand1
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


main() {
    srand(time(NULL));

    int rl ;
    int cont;
    int min,max;
    do
    {
    printf("inserisci il limite minimo ");
    scanf("%d", &min);
    printf("inserisci il limite massimo ");
    scanf("%d", &max);
    }while (min > max);
    for (cont=0;cont<20; cont++) {

        rl = min + rand() % (max +1 - min);
        printf("%d", rl);
        printf("\n");

    }
}
