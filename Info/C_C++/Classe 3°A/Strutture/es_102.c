/*
author: Prandi Alessandro
date: 10/05/2023
es: 102
testo
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LUNG 20
#define MAX_VOTI 2
#define MAX_GIORNO 31
#define MAX_MESE 12
#define MAX_ANNO 2023
#define MAX_VOTI 2
#define DIM 35


typedef struct {

    int giorno;
    int mese;
    int anno;

} Data;

typedef struct {

    Data voto;
    float voto_preso;

} Voto;


typedef struct {

    char nome [LUNG];
    char cognome [LUNG];
    Data nascita;
    Voto voti[MAX_VOTI];

} Persona;

void visDati(Persona per, int max) {

    printf("%s %s ", per.nome, per.cognome);
    printf("nato il %d/%d/%d", per.nascita.giorno, per.nascita.mese, per.nascita.anno);
    for(int k = 0; k < max; k++) {
        printf("\nnella data: %d/%d/%d ha preso %.2f", per.voti[k].voto.giorno,
               per.voti[k].voto.giorno, per.voti[k].voto.anno,
               per.voti[k].voto_preso);
    }
}

void visClasse(Persona tab[], int n, int nvoti){
    for (int k = 0; k < n; k++){
        visDati(tab[k],nvoti);
        printf("\n");
    }
}

int main () {
    Persona classe[DIM];
    char nomeFile[LUNG] = "pagella.dat";
    FILE *fp;
    int nStud = 0;

    fp=fopen(nomeFile, "r");
    if(fp == NULL){
        printf("il file %s non esiste\n", nomeFile);
    }
    else{
        while(nStud < DIM && fscanf(fp, "%s", classe[nStud].nome)!= EOF) {
            fscanf(fp, "%s", classe[nStud].cognome);
            fscanf(fp, "%d/%d/%d", &classe[nStud].nascita.giorno, &classe[nStud].nascita.mese, &classe[nStud].nascita.anno);
            for(int k = 0; k < MAX_VOTI; k++){
                fscanf(fp, "%d/%d/%d", &classe[nStud].voti[k].voto.giorno, &classe[nStud].voti[k].voto.mese, &classe[nStud].voti[k].voto.anno);
                fscanf(fp, "%f", &classe[nStud].voti[k].voto_preso);
            }
            nStud ++;
        }
    }
    fclose(fp);

    visClasse(classe, nStud, MAX_VOTI);
return 0;
}
