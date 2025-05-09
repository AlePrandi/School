/*
author: Prandi Alessandro
date: 10/04/2023
es. 49
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG_MAX 100

void rimuoviVocali(char s[]) {
    int k, j;
    j = 0;
    for (k = 0; s[k] != '\0'; k++) {
        if (s[k] != 'a' && s[k] != 'e' && s[k] != 'i' && s[k] != 'o' && s[k] != 'u' && s[k] != 'A' && s[k] != 'E' && s[k] != 'I' && s[k] != 'O' && s[k] != 'U') {
            s[j++] = s[k];
        }
    }
    s[j] = '\0';
}

int main() {
    char s[LUNG_MAX];

    printf("Inserisci una parola: ");
    fflush(stdin);
    gets(s);

    rimuoviVocali(s);

    printf("La parola senza vocali e: %s", s);

    return 0;
}
