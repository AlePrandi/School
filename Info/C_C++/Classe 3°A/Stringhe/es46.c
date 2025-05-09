/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 100

void invertiStr(char s[], char sInv[]) {
    int n = strlen(s);
    for(int k = 0; k < n - 1; k++) {
        sInv[k]= s[n - k - 1];
    }
    sInv[n] = '\0';
}

int main() {
    char s[LUNG], sInv[LUNG];

    printf("inserisci la stringa: ");
    fflush(stdin);
    gets(s);

    invertiStr(s, sInv);
    printf("stringa invertita: ");
    puts(sInv);

    return 0;
}
