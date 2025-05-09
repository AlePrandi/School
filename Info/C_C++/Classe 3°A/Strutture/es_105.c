/*
author: Prandi Alessandro
date: 16/05/2023
es. 105
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define LUNG 20
#define DIM 100
#define ANNO 2023

typedef struct {
    char descr[LUNG];
    int quant;
    int scadenza;
} Struttura;

int carArc(char nomeFile[], Struttura archivio[], int dim_max) {
    FILE *fp;
    int n = 0;

    fp = fopen(nomeFile, "r");
    if(fp == NULL) {
        printf("file non esistente\n");
    } else {
        while(n < dim_max && fscanf(fp, "%s %d %d", archivio[n].descr,
                                    &archivio[n].quant, &archivio[n].scadenza)!=EOF) {
            n++;
        }
    }
    fclose(fp);
    return n;
}

int contAc(Struttura archivio[], Struttura scaduti[], int n) {
    int j = 0;
    for(int k = 0; k < n; k++) {
        if(archivio[k].scadenza < ANNO) {
            scaduti[j] = archivio[k];
            j++;
        }
    }
    return j;
}
void visualizzaStruttura(Struttura scaduti[], int n) {
    for(int k = 0; k < n; k++) {
        printf("%s ", scaduti[k].descr);
        printf("%d ", scaduti[k].quant);
        printf("%d ", scaduti[k].scadenza);
        printf("\n");
    }
}

int main() {
    Struttura archivio[DIM];
    Struttura scaduti[DIM];
    char nomeFile[LUNG];

    printf("inserire il nome del file: ");
    fflush(stdin);
    scanf("%s", nomeFile);
    int dim = carArc(nomeFile, archivio, DIM);
    int dims = contAc(archivio, scaduti, dim);
    visualizzaStruttura(scaduti, dims);
    return 0;
}
