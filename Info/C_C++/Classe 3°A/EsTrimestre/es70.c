/*
author: Prandi Alessandro
date: 21/11/2022
es. 70
testo
*/

#include <stdio.h>
#include <stdlib.h>

main() {
    int n,cn;
    float num,max;

    do {
        printf("insersici un numero: ");
        scanf("%d", &n);
    } while(n < 0);

    cn = 0;
    for(cn=0; cn<n; cn++) {
        printf("inserire un numero: ");
        scanf("%f", &num);
        if(cn == 0)
            max=num;
        else if(num > max)
            max=num;
    }
    if(n != 0)
        printf("il numero massimo e: %.2f", max);
    else
        printf("non e stato inserito nessun numero");
}
