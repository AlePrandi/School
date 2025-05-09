/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>

int MCD(int m, int n) {
    int r;
    r = m % n;
    if (r == 0) {
        return n;
    } else
        return MCD(n, r);
}
int inserisciPositivi() {
    int n;
    do {
        scanf("%d", &n);
    } while (n <= 0);
    return n;
}

int main() {
    int n1,n2;
    printf("inserisci il primo numero: ");
    n1 = inserisciPositivi();
    printf("inserisci il secondo numero: ");
    n2 = inserisciPositivi();
    printf("il massimo comune divisore e: %d", MCD(n1,n2));
    return 0;
}
