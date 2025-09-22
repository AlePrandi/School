/*
author: Prandi Alessandro
date:
es. 1
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define LUNG 20

void stampaMat(int mat[][LUNG], int nri, int ncl){
for(int r = 0; r < nri;r++){
    for(int c = 0;c < ncl;c++){
        printf("%d", mat[r][c]);
    }
 }
}

int main(){
FILE *fp;
int nr,nc;
fp = fopen("es1.txt", "r");
if (fp == NULL)
{
    printf("file non trovato");
    fopen("es1.txt", "w");
    printf("\nfile creato");
}else{
    fscanf(fp,"%d", &nr);
    fscanf(fp,"%d", &nc);

 int mat[nr][nc];

 for(int r = 0; r < nr;r++){
    for(int c = 0;c < nc;c++){
        fscanf(fp,"%d", &mat[r][c]);
    }
 }
fclose(fp);
 printf("il numero di righe e: %d", nr);
 printf("\nil numero di colonne e: %d", nc);

 stampaMat(mat, nr, nc);

}

return 0;
}
