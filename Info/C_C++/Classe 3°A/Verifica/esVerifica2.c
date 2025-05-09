/*
author: Prandi Alessandro
date: 03/05/2023
es. verifica2
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 20

void rimuoviLett(char frase[],char lett) {
    int k, j, n_lett;
    int pos[LUNG];
    j = 0;
    for (k = 0; frase[k] != '\0'; k++) {
        if(frase[k] != lett){
            frase[j] = frase[k];
            pos[j] = k;
            j++;
        }else{
        n_lett++;
        }
}
frase[j] = '\0';
printf("La parola senza lettera e: %s", frase);
printf("\n%c compare %d volte nelle posizioni ", lett, n_lett);
for(int m = 0; m < n_lett; m++){
    printf("%d, ", pos[m]);
}
}

int main() {
    char frase[LUNG];
    char lett;

    printf("Inserisci una parola: ");
    fflush(stdin);
    gets(frase);
    printf("Quale Lettera vuoi rimuovere: ");
    scanf("%c", &lett);

    rimuoviLett(frase, lett);

    return 0;
}
