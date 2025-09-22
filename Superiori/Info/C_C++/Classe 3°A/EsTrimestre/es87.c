/*
author: Prandi Alessandro
date: 27/11/2022
es. 87
testo
*/

#include <stdio.h>
#include <stdlib.h>

main () {
    int n, cont, tot1, tot2, resto;
    float num, nmin1, nmin;

    do {
        printf("inserisci il numero di numeri: ");
        scanf("%d", & n);
    } while (n < 0);

    cont = 0;
    tot1 = 0;
    tot2 = 0;

    for (cont = 0; cont < n; cont ++) {
        printf("inserisci un numero: ");
        scanf("%f", & num);

        if (tot1 = 0)
            nmin = num;       //primo numero dispari

        if (tot2 = 0)         //primo numero pari
            nmin1 = num;

        resto = cont % 2;

        if (resto = 0) {
            tot1 = 1;
            if (num < nmin)
                nmin = num;
            else
                tot2 = 1;
            if (num < nmin1)
                nmin1 = num;
        }
    }
    if (n < 1)
        printf("non esiste il minore");

    else if (nmin1 < nmin)
        printf("e' minore");
    else
        printf("non e' minore");
}
