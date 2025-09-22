/*
author: Prandi Alessandro
date: 1/12/2022
es.switch procedure
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN -10
#define MAX 20

void giud(int voto) {
    switch(voto) {
    case 1:
    case 2:
        printf("nullo\n");
        break;
    case 3:
    case 4:
        printf("gravemente insufficiente\n");
        break;
    case 5:
        printf("insufficiente\n");
        break;
    case 6:
        printf("sufficiente\n");
        break;
    case 7:
        printf("discreto\n");
        break;
    case 8:
        printf("buono\n");
        break;
    case 9:
        printf("ottimo\n");
        break;
    case 10:
        printf("eccellente\n");
        break;

    default:
        printf("non valutabile\n");

    }

}
main() {
    srand(time(NULL));// fa partire una successione di numeri casuale a partire dal tempo attuale di esecuzione
    int voto,cont,n;
    printf("quanti numeri vuoi generare? ");
    scanf("%d", &n);
    for (cont = 0; cont < n; cont++) {
        voto = MIN + rand() % (MAX + 1 - MIN);
        printf("\n%d\n",voto);
        giud(voto);
    }
}
