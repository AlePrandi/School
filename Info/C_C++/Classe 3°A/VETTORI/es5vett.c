/*
author: Prandi Alessandro
date: 21/02/2023
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 5

float pot(float base, int esp) {
    float ris;
    if (esp == 0 && base == 0) {
        printf("non si puo fare");
        ris = 0;
    } else if (esp < 0) {
        esp = -1 * esp;
        ris = pot( 1/base, esp);
    } else if ( esp == 0) {
        ris = 1;
    } else
        ris = base * pot(base, esp - 1);
    return ris;
}
/*
for(k = 0; k < n;k++){
    if ( k == 0)
        v[k] = 1;
    else
    v[k] = num * v[k - 1];
*/

void potVett(int num,int v1[], int n) {
    for( int k = 0; k < n; k++) {
        v1[k]= pot(num, k);
    }
}

void stampaVett(int v[], int n) {
    for( int k = 0; k < n; k++) {
        printf("%d ", v[k]);
    }
}
int main() {
    int vettA[DIM];
    int vettB[DIM];
    int num;

    printf("inserisci un numero: ");
    scanf("%d", &num);

    potVett(num, vettB, DIM);

    stampaVett(vettB, DIM);

    return 0;
}
