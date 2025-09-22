/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define NC 10
#define DIM 100

int main() {

    int nr, r, c;
    FILE *fp;
    FILE *fp1;
    int mat[DIM][NC];

    fp = fopen("es3.txt", "r");
    fp1 = fopen("somme.txt", "w");
    if (fp == NULL) {
        printf("file non esistente\n");
    } else {
        r = 0;
        while(r < DIM && fscanf(fp, "%d", &mat[r][0]) != EOF) {

            for (c= 1; c < NC; c++) {
                fscanf(fp, "%d", &mat[r][c]);

            }
            r++;
        }
        fclose(fp);
        nr = r;
        for (r = 0; r < nr; r++) {
            for (c = 0; c < NC; c++) {
                printf("%d ", mat[r][c]);
            }
            printf("\n");
        }
    }
    return 0;
}
