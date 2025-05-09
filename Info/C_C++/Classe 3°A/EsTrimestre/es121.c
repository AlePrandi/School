/*
author: Prandi Alessandro
date: 24/01/2023
es. 121
testo
*/

#include <stdio.h>
#include <stdlib.h>

void classe() {
    float stud, punt, max,pncl, med,cl, nstud; //pncl = punteggio classe
    for (int a = 0; a < 5; a++){
    cl = cl + 1;
    printf("inserisci il numero di studenti nella classe: ");
    scanf("%f", &stud);
    for (int k= 0; k < stud; k++) {
        nstud = nstud + 1;
        printf("inserisci il punteggio dello studente: ");
        scanf("%f", &punt);
        pncl= pncl + punt;
        if ( k = 0 || punt > max) {
            max = punt;
        }
    }
    if ( a = 3 && stud != 0){
     med = pncl / stud;
     printf("la media e: %.2f", med);
    }
    else
        printf("non ci sono studenti");
    }
printf("lo studente con il punteggio piu alto e il n. %.0f della classe %.0f", nstud, cl);
}

int main() {

    return 0;
}
