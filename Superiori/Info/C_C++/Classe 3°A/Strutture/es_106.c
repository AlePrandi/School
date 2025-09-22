/*
author: Prandi Alessandro
date: 16/05/2023
es. 106
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LUNG 20
#define MAX_pren 100
#define LIM 30

typedef struct {
    char cognome[LUNG];
    int data;
} Prenotazione;

int carPren(char nomeFile[], Prenotazione pren[]) {
    FILE *fp;
    int npren = 0;

    fp = fopen(nomeFile,"r");

    if(fp == NULL) {
        printf("il file non esiste\n");
    } else {
        while(npren < MAX_pren && fscanf(fp, "%s %d", pren[npren].cognome, &pren[npren].data) != EOF) {

            npren++;
        }
    }
    fclose(fp);
    return npren;
}

void visDati(Prenotazione appuntamento) {
    printf("%s ", appuntamento.cognome);
    printf("%d", appuntamento.data);
}

void vispren(Prenotazione pren[], int npren) {
    for(int k = 0; k < npren; k++) {
        visDati(pren[k]);
        printf("\n");
    }
}

int cercaGiorni(Prenotazione pren[], int n, int x) {
    int tro, k;
    tro = -1;
    k = 0;
    while ((k < n) && (tro == -1)) {
        if(x == pren[k].data)
            tro = k;
        else
            k++;
    }
    return tro;
}

void giorniLib(Prenotazione pren[], int npren) {
    int giorno = 1;
    for(int k = 0; k < LIM; k++) {
        if (cercaGiorni(pren, npren, giorno) == -1){
            printf("%d\n", giorno);
        }
        giorno++;
    }
}

void appGiorno(Prenotazione pren[], int npren, int giorno){
    int tro = cercaGiorni(pren, npren, giorno);
    if(tro != -1){
        visDati(pren[tro]);
        printf("\n");
    }
}

int main() {
    Prenotazione pren[MAX_pren];
    char nomeFile[LUNG];
    int giorno;

    printf("inserire il nome del file: ");
    fflush(stdin);
    scanf("%s", nomeFile);
    int npren = carPren(nomeFile, pren);
    vispren(pren, npren);
    printf("\nGiorni liberi: \n");
    giorniLib(pren, npren);
    printf("\nInserisci un giorno: ");
    scanf("%d", &giorno);
    appGiorno(pren, npren, giorno);

return 0;
}
