 /*
author: Prandi Alessandro
date:
es. 63
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define MAXR 5
#define MAXC 7

int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserire il numero caselle [0..%d]: ", dimMax);
        scanf("%d", &x);
    } while (x < 0 || x > dimMax);
}

void LeggiRiga(float mat[][MAXC], int nr, int nc) {
    for (int r = 0; r < nr; r++)
        for(int c = 0; c < nc; c++) {
            printf("elemento in posizione[%d][%d]: ", r, c);
            scanf("%f", &mat[r][c]);
        }
}

void stampa(float mat[][MAXC], int nr, int nc) {
    for (int r = 0; r < nr; r++)
        for(int c = 0; c < nc; c++) {
            printf("%.2f", mat[r][c]);
        }
}

void med(float mat[][MAXC], int nr, int nc, int media[]) {
    if(nr != 0) {
        for(int r = 0; r < nr; r ++) {
            media[r]= 0;
            for(int c = 0; c < nc; c++) {
                media[r] += mat[r][c];
            }
            media[r] = media[r]/ nc;
        }
    }


}

int main() {
    float voti[MAXR][MAXC];

    int nAlunni = chiediDim(MAXR);
    int nVoti = chiediDim(MAXC);

    LeggiRiga(voti, nAlunni, nVoti);

    return 0;
}
