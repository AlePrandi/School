/*
author: Prandi Alessandro
date: 12/12/2022
es. I
testo
*/

#include <stdio.h>
#include <stdlib.h>

int magg(int a, int b) {
    float mag;
    if (a > b)
        mag = a;
    else
        mag = b;
    return mag;
}

int main() {
    float n1,n2;
    float mag;
    printf("inserisci un numero: ");
    scanf("%f", &n1);
    printf("inserisci un numero: ");
    scanf("%f", &n2);
    mag = magg(n1, n2);
    printf("il maggiore e: %.2f", mag);
    return 0;
}
