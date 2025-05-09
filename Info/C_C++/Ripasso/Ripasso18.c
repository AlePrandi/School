/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG_MAX 100
#define CONV 32

void CambiaMaius(char str[]) {
    int k;
    for (k = 0; str[k] != '\0'; k++) {
        if (str[k] >= 'a' && str[k] <= 'z'){
        str[k] = str[k] - CONV;
        }
    }
    str[k] = '\0';
}

int main() {
    char str[LUNG_MAX];

    printf("Inserisci una parola: ");
    fflush(stdin);
    gets(str);

    CambiaMaius(str);

    printf("La parola in maiuscolo e: %s", str);

    return 0;
}