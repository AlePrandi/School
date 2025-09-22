/*
author: Prandi Alessandro
date:5/12/2022
es. E
testo
scrivere la procedura che ricevuta una data g/m/a la scrive a video con il mese in lettere
*/

#include <stdio.h>
#include <stdlib.h>
int g,m,a;
void mese(int m) {
    switch (m) {
    case 1:
        printf(" la data e %d gennaio %d",g,a);
        break;
    case 2:
        printf("la data e %d febbraio %d",g,a);
        break;
    case 3:
        printf("la data e %d marzo %d",g,a);
        break;
    case 4:
        printf("la data e %d aprile %d",g,a);
        break;
    case 5:
        printf("la data e %d maggio %d",g,a);
        break;
    case 6:
        printf("la data e %d giugno %d",g,a);
        break;
    case 7:
        printf("la data e %d luglio %d",g,a);
        break;
    case 8:
        printf("la data e %d agosto %d",g,a);
        break;
    case 9:
        printf("la data e %d settembre %d",g,a);
        break;
    case 10:
        printf("la data e %d ottobre %d",g,a);
        break;
    case 11:
        printf("la data e %d novembre %d",g,a);
        break;
    case 12:
        printf("la data e %d dicembre %d",g,a);
        break;
    default:
        printf("inserire un mese valido");
        break;
    }
}
main() {


    printf("inserire giorno mese e anno\n");
    scanf("%d/%d/%d", &g, &m, &a);
    mese(m);
}
