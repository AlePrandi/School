/*
author: Prandi Alessandro
date:11/12/2022
es. D
testo
*/

#include <stdio.h>
#include <stdlib.h>


void eta(int e1, int e2, int e3) {
    if (e1 > e2) {
        if (e1 > e3) {
            if (e2 > e3) {
                printf("%d, %d, %d", e1, e2, e3);
            } else {
                printf("%d, %d, %d", e1, e3, e2);
            }
        } else {
            printf("%d, %d, %d", e3, e1, e2);
        }
    } else {
        if (e2 > e3) {
            if (e1 > e3) {
                printf("%d, %d, %d", e2, e1, e3);
            } else {
                printf("%d, %d, %d", e2, e3, e1);
            }
        } else
            printf("%d, %d, %d", e3, e2, e1);
    }
}
int numneg() {
int n;
do {
    scanf("%d", &n);
    if (n < 0)
        printf("valore non valido, inserisci un altro numero: ");
}while(n<0);
return n;
}

int main () {
    int e1, e2, e3;

    printf("inserisci l'eta della prima persona: ");
    e1 = numneg();
    printf("inserisci l'eta della seconda persona: ");
    e2 = numneg();
    printf("inserisci l'eta della terza persona: ");
    e3 = numneg();
    eta(e1, e2, e3);
return 0;
}
