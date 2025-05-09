/*
author: Prandi Alessandro
date: 7/12/2022
es. Prandi 1
testo
Dato un numero compreso tra 1 e 12 (controllare che sia valido),
scrivere a quale mese corrisponde e a quale stagione.
Fare attenzione ai mesi a cavallo tra due stagioni.
*/

#include <stdio.h>
#include <stdlib.h>

int main() {
    int num,g;
    do {
        printf("inserisci un mese: ");
        scanf("%d", &num);
    } while(num < 0 || num > 12);
    switch(num) {
    case 1:
        printf("mese : gennaio");
        printf("stagione: inverno");
        break;
    case 2:
        printf("mese : febbraio");
        printf("stagione: inverno");
        break;
    case 3:
        printf("mese : marzo\n");
        printf("inserisci il giorno: ");
        scanf("%d", &g);
        if(g >= 21)
            printf("stagione: primavera");
        else
            printf("stagione: inverno");
        break;
    case 4:
        printf("mese : aprile\n");
        printf("stagione: primavera");
        break;
    case 5:
        printf("mese : maggio\n");
        printf("stagione: primavera");
        break;
    case 6:
        printf("mese : giugno\n");
        printf("inserisci il giorno: ");
        scanf("%d", &g);
        if(g >= 21)
            printf("stagione: estate");
        else
            printf("stagione: primavera");
        break;
    case 7:
        printf("mese : luglio\n");
        printf("stagione: estate");
        break;
    case 8:
        printf("mese : agosto\n");
        printf("stagione: estate");
        break;
    case 9:
        printf("mese : settembre\n");
        printf("inserisci il giorno: ");
        scanf("%d", &g);
        if(g >= 23)
            printf("stagione: autunno");
        else
            printf("stagione: estate");
        break;
    case 10:
        printf("mese : ottobre\n");
        printf("stagione: autunno");
        break;
    case 11:
        printf("mese : novembre\n");
        printf("stagione: autunno");
        break;
    case 12:
        printf("mese : dicembre\n");
        printf("inserisci il giorno: ");
        scanf("%d", &g);
        if(g >= 21)
            printf("stagione: inverno");
        else
            printf("stagione: autunno");
        break;
    }
    return 0;
}
