/*
author: Prandi Alessandro
date: 27/11/2022
es. 84
testo
*/

#include <stdio.h>
#include <stdlib.h>

main () {
    int a, b;   //dividendo e divisore
    float r, q;      //resto e quoziente

    do {
        printf("inserisci il primo numero: ");
        scanf("%d", & a);
    } while (a < 0);

    do {
        printf("inserisci il secondo numero: ");
        scanf("%d", & b);
    } while (b < 0);

    r = a;
    q = 0;

    while (r >= b) {
        r = r - b;
        q = q + 1;
    }

    printf("il quoziente della divisione e': %f\n", q);
    printf("il resto della divisione e' %f: ", r);

}
