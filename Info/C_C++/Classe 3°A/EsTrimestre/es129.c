/*
author: Prandi Alessandro
date: 23/11/2022
es. 129
testo
*/

#include <stdio.h>
#include <stdlib.h>

main() {
    int k,j;

    k=0;
    for(k=1; k<=10; k++) {
        for(j=1; j<=10; j++) {
            printf("%5d",k*j);//%5d per allineare e spostare 5 caselle a destra
        }
        printf("\n");
    }
}
