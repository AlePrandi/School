/*
author: Prandi Alessandro
date: 12/04/2023
es. tabellina pitagorica
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXR 10
#define MAXC 10

void tabellPita(int mat[][MAXC], int nr, int nc) {
    for(int r = 0; r < nr; r++) {
        for(int c = 0; c < nc; c++) {
            mat[r][c] = r * c;
        }
    }
}

void visTab(int mat[][MAXC], int nr, int nc) {
    for(int r = 0; r < nr; r++) {
        for(int c = 0; c < nc; c++) {
            printf("%d\t", mat[r][c]);
        }
        printf("\n");
    }
}

int main() {

    int tab[MAXR][MAXC];


    tabellPita(tab, MAXR, MAXC);

    visTab(tab, MAXR, MAXC);
    return 0;
}
