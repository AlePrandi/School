/*
author: Prandi Alessandro
date: 29/11/2022
es. 111
testo
*/

#include <stdio.h>
#include <stdlib.h>

main() {
    int n,somma,cont,disp;
    do {
        printf("inserire un numero: ");
        scanf("%d", &n);
    } while(n < 0);
    somma = 0;
    disp = 1;
    for(cont= 0; cont < 0; cont++) {
        somma = somma + disp;
        disp = disp + 2;
        cont++;
    }
    if(somma == n*n) //controllo se la somma corrisponde al quadrato di n
        printf("somma e quadrato corrispondono");
    else
        printf("somma e quadrato non corrispondono");
}
