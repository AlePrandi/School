/*
author: Prandi Alessandro
date: 14/12/2022
es. H
testo
*/

#include <stdio.h>
#include <stdlib.h>

void max(int num1, int num2) {
    int nmax;
    if (num1 > num2)
        nmax  = num1;
    else if (num2 > num1)
        nmax = num2;
    else {
        printf("i numeri sono uguali");
    }

    printf("il magiore e %d", nmax);
}

int main() {
    int num1,num2;
    printf("inserisci il primo numero: ");
    scanf("%d", &num1);
    printf("inserisci il secondo numero: ");
    scanf("%d", &num2);
    max(num1, num2);
return 0;
}
