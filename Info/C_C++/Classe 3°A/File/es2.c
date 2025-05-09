/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define NC 5

void stampaMat(int mat[][NC], int nri, int ncl){
for(int r = 0; r < nri;r++){
    for(int c = 0;c < ncl;c++){
        printf("%d", mat[r][c]);
    }
 }
}

int main(){
FILE *fp;
int nr;
fp = fopen("es2.txt", "r");
if (fp == NULL)
{
    printf("file non trovato");
    fopen("es2.txt", "w");
    printf("\nfile creato");
}else{
    fscanf(fp,"%d", &nr);


 int mat[nr][NC];

  for(int r = 0; r < nr;r++){
    for(int c = 0;c < NC;c++){
        fscanf(fp,"%d", &mat[r][c]);
    }
 }
 fclose(fp);
stampaMat(mat,nr, NC);
}

return 0;
}
