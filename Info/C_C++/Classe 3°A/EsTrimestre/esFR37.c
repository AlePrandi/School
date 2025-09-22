/*
author: Prandi Alessandro
date: 25/01/2023
es. 37
testo
*/

#include <stdio.h>
#include <stdlib.h>
float pot(float base, int esp) {
    float ris;
    if (esp == 0 && base == 0) {
        printf("non si puo fare");
        ris = 0;
    } else if (esp < 0) {
        esp = -1 * esp;
        ris = pot( 1/base, esp);
    } else if ( esp == 0) {
        ris = 1;
    } else
        ris = base * pot(base, esp - 1);
    return ris;
}

int main() {
    float b,risul;
    int e;
    printf("inserisci base ed esponente: ");
    scanf("%f %d", &b, &e);
    risul = pot( b, e);
    printf("il risultato e: %.2f", risul);
    return 0;
}
