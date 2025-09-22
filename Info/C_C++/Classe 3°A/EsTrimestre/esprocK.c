/*
author: Prandi Alessandro
date: 14/12/2022
es. K
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool istriang(float n1, float n2, float n3) {
    bool eTriangolo;
    if  ((n1 < n2+n3) &&
            (n2 < n1+n3) &&
            (n3 < n1+n2)) {
        eTriangolo = true ;
    } else
        eTriangolo = false ;
}

int numneg() {
    int n;
    do {
        scanf("%d", &n);
        if (n <= 0)
            printf("valore non valido, inserisci un altro numero: ");
    } while(n<0);
    return n;
}

int main() {
    float l1,l2,l3;

    printf("inserisci il primo lato: ");
    l1 = numneg();
    printf("inserisci il secondo lato: ");
    l2 = numneg();
    printf("inserisci il terzo lato: ");
    l3 = numneg();
    if (istriang(l1,l2,l3) == true)
        printf("puo essere un triangolo");
    else
        printf("non puo essere un triangolo");
    return 0;
}
