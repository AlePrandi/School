/*
author: Prandi Alessandro
date: 18/12/2022
es. L
testo
*/

#include <stdio.h>
#include <stdlib.h>
void eVocale(char lettera) {
    switch (lettera) {
    case 'a':
        printf("e una vocale");
        break;
    case 'e':
        printf("e una vocale");
        break;
    case 'i':
        printf("e una vocale");
        break;
    case 'o':
        printf("e una vocale");
        break;
    case 'u':
        printf("e una vocale");
        break;
    default:
        printf("non e una vocale");
    }
}

int main() {
    char lettera;
    printf("inserisci una lettera: ");
    scanf("%c", &lettera);
    eVocale(lettera);
return 0;
}
