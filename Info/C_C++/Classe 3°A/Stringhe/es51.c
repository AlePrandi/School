/*
author: Prandi Alessandro
date: 10/04/2023
es. 51
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG_MAX 100

int NonOrdNonDisg(char s[], int n) {
    int nx;
    for (int k = 0; s[k] != '\0'; k++) {
        if (s[k] >= '0' && s[k] <= '9') {
            nx++;
        }
    }
    s[n] = '\0';
    return nx;
}

int main() {
    char s[LUNG_MAX];
    int n_car;

    printf("Inserisci una frase di massimo 100 caratteri: ");
    fflush(stdin);
    gets(s);

    n_car = NonOrdNonDisg(s,LUNG_MAX);

    printf("Caratteri numerici presenti: %d", n_car);
    return 0;
}
