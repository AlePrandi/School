/*
author: Prandi Alessandro
date:05/04/2023
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N_ALUNNI 25
#define LUNG 20

int chiediDim(int max) {
    int x;
    do {
        printf("inserisci dimensione del vettore[0...%d]: ", max);
        scanf("%d", &x);
    } while(x < 0 || x > max);
    return x;
}

void PrimaMaiusc(char mat[] [LUNG], int n){
    for(int k = 0; k < n; k ++){
        if(mat[k][0] >= 'a' && mat[k][0] <= 'A'){
            mat[k][0] = mat[k][0] - ('a' - 'A');
        }
    }
}

void leggiElenco(char mat[][LUNG], int nr) {
    for (int k = 0; k < nr; k++) {
        printf("inserisci il nome del %d^ alunno: ", k);
        fflush(stdin);
        gets(mat[k]);
    }
}

void scambio(char s1[], char s2[]) {
    char temp[LUNG];
    strcpy(temp, s1);
    strcpy(s1, s2);
    strcpy(s2, temp);
}

void ordinaElenco(char mat[][LUNG], int n) {
    int k,sup;

    for(sup = n - 1; sup > 0; sup--) {
        for(k = 0; k < sup; k++) {
            if(strcmp(mat[k], mat[k + 1]) > 0) {
                scambio(&mat[k], &mat[k + 1]);
            }
        }
    }
}

void VisElenco(char mat[][LUNG], int nr) {
    for (int k = 0; k < nr; k++) {
        printf("\n%s",mat[k]);
    }
}

void bubble1(char mat[][LUNG], int n) {
    int k,sup;
    for(sup = n - 1; sup > 0; sup--) {
        for(k = 0; k < sup; k++) {
            if(strcmp(mat[k], mat[k + 1]) > 0) {

            }
        }
    }
}

int main() {
    char elenco[N_ALUNNI][LUNG];

    int n = chiediDim(N_ALUNNI);

    leggiElenco(elenco, n);
    PrimaMaiusc(elenco, n);
    ordinaElenco(elenco, n);
    VisElenco(elenco, n);
    return 0;
}
