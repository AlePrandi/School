/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 100

int main(){
    char s[DIM];

    printf("Lettura di una stringa con scanf: ");
    fflush(stdin);
    scanf("%s", s);

    for(int k = 0; s[k] != '\0';k++){
        printf("%c-", s[k]);
    }

    printf("\n");
    int n= strlen(s);
    for(int k=0; k < n - 1;k++){
        printf("%c-", s[k]);
    }
    printf("%c-", s[n -1]);
return 0;
}
