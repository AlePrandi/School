/*
author: Prandi Alessandro
date: 10/04/2023
es. 52
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG_MAX 100

void scambioP_U(char s[]) {
    int lung = strlen(s);
    if (lung < 2) {

        return;
    }
    char primo = s[0];
    s[0] = s[lung - 1];
    s[lung - 1] = primo;
}

int main() {
    char s[LUNG_MAX];
    printf("inserisci una stringa: ");
    fflush(stdin);
    gets(s);
    scambioP_U(s);
    printf("Stringa scambiata: %s\n", s);
    return 0;
}
