/*
author: Prandi Alessandro
date:30/11/2022
es.asterischi
testo
*/

#include <stdio.h>
#include <stdlib.h>

void visAst(int n) {
    int k;
    for(k=0; k <n; k++) {
        printf("*");
    }
}
int contr() {
    int num;
    do {
        scanf("%d", &num);
    } while(num < 0);

    return num;
}
main() {
    int k;
    int ast;
    int vol;

    printf("inserisci il numero di asterischi: ");
    ast= contr();
    printf("inserisci il numero di volte: ");
    vol= contr();

    for(k = 0; k < vol; k++) {
        visAst(ast);
        printf("\n");
    }
}
