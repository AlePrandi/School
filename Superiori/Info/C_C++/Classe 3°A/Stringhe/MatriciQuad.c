/*
author: Prandi Alessandro
date: 13/04/2023
es. matrici quadrate
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 5
#define MIN -10
#define MAX 10

int diagPrinc(int mat[][DIM], int nr) {
    int somma;
    for(int r = 0; r < nr;r ++){
        somma = somma + mat[r][r];
    }
return somma;
}

int diagSec(int mat[][DIM], int nr, int nc) {
    int somma;
    for(int r = 0; r < nr;r++)
    for(int c = nc - 1; c > nc; c--){
        somma = somma + mat[r][c];
    return somma;
}
}

void CarCas(int mat[][DIM],int nr, int nc,int min, int max) {
    srand(time(NULL));
    for(int r = 0; r < nr; r++)
        for(int c = 0; c < nc; c++) {
            mat[r][c] = MIN + rand() % (MAX + 1 - MIN);
        }
}

void stampa(int mat[][DIM], int nr, int nc) {
    for (int r = 0; r < nr; r++)
        for(int c = 0; c < nc; c++) {
            printf("%d\t", mat[r][c]);
        }
        printf("\n");
}

int main() {
    float mat[DIM][DIM];
    int s1,s2;

    CarCas(mat, DIM, DIM, MIN, MAX);
    stampa(mat, DIM, DIM);

    s1 = diagPrinc(mat, DIM);
    s2 = diagSec(mat, DIM, DIM);

    return 0;
}
