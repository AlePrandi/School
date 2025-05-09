/*
author: Prandi Alessandro
date: 21/11/2022
es. 75
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define  ALTM 180

main() {
    int n,alt,k,nper;

    do {
        printf("inserire il numero di persone: ");
        scanf("%d", &n);
    } while(n < 0);
    k=0;
    nper=0;
    for(k=0; k<n; k++) {
        printf("inserire l'altezza della persona: ");
        scanf("%d", &alt);
        if(alt > ALTM)
            nper++;
    }
    if(n!= 0)
        printf("le persone piu alte di 180 cm sono %d",nper);
}
