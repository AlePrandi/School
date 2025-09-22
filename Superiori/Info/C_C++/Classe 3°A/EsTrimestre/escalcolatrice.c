/*
author: Prandi Alessandro
date: 16/11/2022
es.calcolatrice
testo
*/

#include <stdio.h>
#include <stdlib.h>

main() {
    float n1,n2,ris;
    char op,risp;
    do {
        printf("insersici il primo numero: ");
        scanf("%f", &n1);
        printf("insersici il secondo numero: ");
        scanf("%f", &n2);
        printf("inserisci l'operazione da fare: ");
        fflush(stdin);
        scanf("%c",&op);
        switch(op) {

        case '+' :
            ris = n1 + n2;
            break;

        case '-' :
            ris = n1 - n2;
            break;

        case '*' :
            ris = n1 * n2;
            break;

        case '/' :
            ris = n1 / n2;
            break;

        default :
            printf("l'operatore non esiste");
        }
        printf("il risultato e %.2f \n", ris);
        printf("ce ne ancora ?: ");
        fflush(stdin);
        scanf("%c",&risp);
    } while(risp!='n' || risp != 'N');
}
