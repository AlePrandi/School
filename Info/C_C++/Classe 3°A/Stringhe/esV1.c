/*
author: Prandi Alessandro
date:
es. provaV 1
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 6

void CaricaMat(int mat[][LUNG], int r, int c) {
    for(int nr = 0; nr < r; nr++) {
        for(int nc = 0; nc < c; nc++) {
            printf("inserisci un numero[%d][%d]: ", nr + 1,nc + 1);
            scanf("%d", &mat[nr][nc]);
        }
    }
}

void stampaMat(int mat[][LUNG], int r, int c) {
    printf("\n");
    for(int nr = 0; nr < r; nr++) {
        for(int nc = 0; nc < c; nc++) {
            printf("%d ", mat[nr][nc]);
        }
        printf("\n");
    }
}

bool Epal(int mat[][LUNG],int vett[LUNG], int r, int c) {
    int k,j,somma;
    bool sonoPal;
    sonoPal = true;
    k = 0;
    while(k < r/2 && sonoPal == true) {
        for(int nr = 0; nr < r; nr++) {
            somma = 0;
            for(int nc = 0; nc < c; nc++) {
                somma = somma + mat[nr][nc];
            }
            vett[k] = somma;
        }
        if(vett[k] == vett[r - k - 1]) {
            sonoPal = false;
        } else {
            k++;
        }
    }
    return sonoPal;
}

int main() {
    int mat[LUNG][LUNG];
    int somma[LUNG];

    CaricaMat(mat, LUNG, LUNG);
    stampaMat(mat, LUNG, LUNG);

    if(Epal(mat,somma, LUNG, LUNG) == true) {
        printf("\nle somme sono palindrome");
    } else {
        printf("\nle somme non sono palindrome");
    }

    return 0;
}
