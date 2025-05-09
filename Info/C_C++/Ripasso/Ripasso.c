/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int NonNeg() {
    int n;
    do {
        printf("inserisci un numero positivo: ");
        scanf("%d", &n);
    } while(n < 0);
    return n;
}

void StampaChar(int nvolte, char c) { // esercizio 1
    for(int k = 0; k < nvolte; k++) {
        printf("%c", c);
    }
}

void StampaQuad(int nvolte, char c) {  // esercizio 2
    for(int k = 0; k < nvolte; k++) {
        StampaChar(nvolte, c);
        printf("\n");
    }
}

void StampaRett(int alt,int lung, char c) { // esercizio 3
    for(int k = 0; k < alt; k++) {
        StampaChar(lung, c);
        printf("\n");
    }
}

void StampaTriang(int n, char c) {  // esercizio 4
    for(int k = 0; k < n; k++) {
        StampaChar(k + 1, c);
        printf("\n");
    }
}

void StampaStrisce(int n, char c,int lung, int alt) { // esercizio 5
    for(int k = 0; k < n; k++) {
        if(k % 2 != 0) {
            StampaRett(alt,lung, '0');
        } else {
            StampaRett(alt,lung, c);
        }
    }
}

int main() {
    int numero = NonNeg(), lung, alt;
    char carattere;
    printf("inserisci il carattere che vuoi stampare: ");
    fflush(stdin);
    scanf("%c", &carattere);
    printf("inserisci la lunghezza: ");
    scanf("%d", &lung);
    printf("inserisci l'altezza: ");
    scanf("%d", &alt);
    StampaStrisce(numero, carattere, lung, alt);

    return 0;
}
