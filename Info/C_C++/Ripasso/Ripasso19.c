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

int isVocali(char s[])
{
    int k, n_voc;
    n_voc = 0;
    for (k = 0; s[k] != '\0'; k++)
    {
        if (s[k] == 'a' || s[k] == 'e' || s[k] == 'i' || s[k] == 'o' || s[k] == 'u' || s[k] == 'A' || s[k] == 'E' || s[k] == 'I' || s[k] == 'O' || s[k] == 'U')
        {
            n_voc++;
        }
    }
    s[k] = '\0';
    return n_voc;
}

int main()
{
    char s[LUNG_MAX];
    int num;
    printf("Inserisci una parola: ");
    fflush(stdin);
    gets(s);

    num = isVocali(s);

    if(num % 2 == 0){
        printf("il numero di vocali è pari");
    }
    else{
        printf("il numero di vocali è dispari");
    }
    return 0;
}
