/*
author: Prandi Alessandro
date: 05/02/2023
es. FR39
testo
*/

#include <stdio.h>
#include <stdlib.h>

int f(int x) {
    if (x == 0) {
        return 0;
    } else {
        return x + f(x -1);
    }
}

int sommaNumeri(int x) {
    int somma;
    if (x == 0) {
        somma = 0;
    } else {
        somma = x + sommaNumeri(x -1);
    }
    return somma;
}

int main() {
    int num;
    do {
        printf("inserisci un numero: ");
        scanf("%d", &num);
    } while(num < 0);
    printf("la somma e: %d", f(num));
    return 0;
}
