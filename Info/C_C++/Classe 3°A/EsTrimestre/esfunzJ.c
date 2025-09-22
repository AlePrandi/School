/*
author: Prandi Alessandro
date: 11/12/2022
es. J
testo
*/

#include <stdio.h>
#include <stdlib.h>

float visMedia(int n, float somma) {
    float media;
    if(n != 0)
        media = somma / n;
    else {
        printf("la media non si puo fare");
        media = 0;
    }
    return media;
}

int main() {
    float num, somma, media;
    int n, cont;

    printf("inserisci il numero di numero dei valori che vuoi inserire: ");
    scanf("%d", &n);
    somma = 0;
    for (cont = 0; cont < n; cont++) {
        printf("inserisci un numero: ");
        scanf("%f", &num);
        somma = somma + num;
    }
    media = visMedia(n, somma);
    printf("la media e: %.2f",media);
    return 0;
}
