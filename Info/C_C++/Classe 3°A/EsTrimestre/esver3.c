/*
author: Prandi Alessandro
date: 11/02/2023
es. verifica 3
testo
*/

#include <stdio.h>
#include <stdlib.h>

void calcolo(int x, int y) {
    int cont = 0;
    do {
        x = x - y;
        cont ++;
    } while (x >= y);
    printf("il quoziente è %d\n", cont);
    printf("il resto è %d\n", x);
}
int contrDiv() {
    int y;
    do {
        printf("inserire il divisore: \n");
        scanf("%d", &y);
    } while (y < 0);
    return y;
}
int main() {
    int n1, n2, n, cont;
    printf("inserire il numero di coppie \n");
    scanf("%d", &n);
    for (cont = 0; cont < n; cont ++) {
        printf("inserire il dividendo: \n");
        scanf("%d", &n1);
        n2 = contrDiv();
        calcolo(n1, n2);
    }
    return 0;
}
