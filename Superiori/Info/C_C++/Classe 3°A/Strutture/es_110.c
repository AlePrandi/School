/*
author: Prandi Alessandro
date: 23/05/2023
es. 110
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 100
#define DIM 3

typedef struct {
    char nomeMat[LUNG];
    float Scritto;
    float Orale;
    float Pratico;
    float Media;
} Materia;

int menu() {
    int scelta;
    printf("0 Esci\n");
    printf("1 Carica voto materia X\n");
    printf("2 Visualizza tutto\n");
    printf("3 Media minima e massima\n");
    printf("\nscelta: ");
    scanf("%d", &scelta);
    return scelta;
}

void CarVoti(Materia s[], int max) {
    for(int k = 0; k < max; k++) {
        printf("inserisci il nome della materia: ");
        fflush(stdin);
        gets(s[k].nomeMat);
        printf("inserisici il voto scritto: ");
        scanf("%f", &s[k].Scritto);
        printf("inserisici il voto orale: ");
        scanf("%f", &s[k].Orale);
        printf("inserisici il voto pratico: ");
        scanf("%f", &s[k].Pratico);
        printf("\n");
        s[k].Media = (s[k].Orale  + s[k].Scritto + s[k].Pratico)/3;
    }
}

void VisVoti(Materia s[], int max) {
    for(int k = 0; k < max; k++) {
        printf("\nMateria: %s ", s[k].nomeMat);
        printf("\nScritto: %.2f", s[k].Scritto);
        printf("\nOrale: %.2f", s[k].Orale);
        printf("\nPratico: %.2f", s[k].Pratico);
        printf("\nMedia: %.2f", s[k].Media);
    }
}

void scambio(Materia c1[],Materia c2[]) {
    Materia *c3;
    c3 = c1;
    c1 = c2;
    c2 = c3;
}

void OrdinaMed(Materia s[], int n) {
    int k,sup,sca;
    sup= n-1 ;
    while ( sup>0 ) {
        sca=0 ;
        for (k = 0; k < sup ; k++) {
            if ( s[k].Media < s[k + 1].Media) {
                scambio(&s[k], &s[k + 1]);
                sca=k ;
            }
        }
        sup=sca ;
    }
}

void MaxMinMed(Materia s[], int max) {
    void OrdinaMed(s, max);
    printf("la materia piu bassa e %s con la media di %.2f", s[1].nomeMat, s[1].Media);
    printf("la materia piu alta e %s con la media di %.2f", s[max - 1].nomeMat, s[max - 1].Media);
}

int main() {
    Materia Pagella[DIM];
    int scelta;
    do {
        scelta = menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            CarVoti(Pagella, DIM);
            break;
        case 2:
            VisVoti(Pagella, DIM);
            break;
        case 3:
            MaxMinMed(Pagella, DIM);
            break;
        }
    } while(scelta != 0);

    return 0;
}
