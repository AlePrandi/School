/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 6

int c1,c2,c3,c4,c5,c6;
void cdado(int dado) {
    switch (dado) {
    case 1:
        c1++;
        break;
    case 2:
        c2++;
        break;
    case 3:
        c3++;
        break;
    case 4:
        c4++;
        break;
    case 5:
        c5++;
        break;
    case 6:
        c6++;
        break;
    }
}


main() {

    srand(time(NULL));
    int nvolte,dado,cont;
    printf("quante volte vuoi tirare il dado? ");
    scanf("%d", &nvolte);
    for (cont = 0; cont < nvolte; cont++) {
        dado= MIN + rand() % (MAX + 1 - MIN);
        cdado(dado);
    }
    printf("il numero 1 e uscito %d volte\n", c1);
    printf("il numero 2 e uscito %d volte\n", c2);
    printf("il numero 3 e uscito %d volte\n", c3);
    printf("il numero 4 e uscito %d volte\n", c4);
    printf("il numero 5 e uscito %d volte\n", c5);
    printf("il numero 6 e uscito %d volte\n", c6);
}
