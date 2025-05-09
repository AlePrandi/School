/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int main() {
    int vett[DIM];
    FILE *fp;
    float media=0;
    int somma=0;
    int dim;
    fp = fopen("numeri.txt","r");
    if (fp == NULL)
        printf("il file non esiste");
    else {
        int k = 0;
        fscanf(fp,"%d",&dim);
        for(k < dim && fscanf(fp,"%d",&vett[k])!= EOF) {
            somma=somma+vett[k];
            k++;
        }
        fclose(fp);
        if(k == 0) {
            printf("impossibile dividere per 0");
        }
        media=(float)somma/k;
        printf("La media vale: %.2f",media);
    }
}
