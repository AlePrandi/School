/*
author: Prandi Alessandro
date: 08/02/2023
es. FR41
testo
*/

#include <stdio.h>
#include <stdlib.h>
int quoz(int a, int b) {

    if (a >= b)
        return 1 + quoz(a-b, b);
    else
        return 0;
}

int main() {
    int divid,divis;
    do {
        printf("inserisci il dividendo: ");
        scanf("%d", &divid);
    } while(divid < 0);
    do {
        printf("inserisci il divisore: ");
        scanf("%d", &divis);
    } while(divis < 1);
    printf("il quoziente e: %d", quoz(divid, divis));
    return 0;
}
