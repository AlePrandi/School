/*
author: Prandi Alessandro
date: 17/05/2023
es. 107
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 20
#define PUNT 10
#define DIM 5
#define G_MAX 8

typedef struct {
    int Pettorale;
    char Nome[LUNG];
    int Punt[PUNT];
    int Tot;
} Atleta;

int menu() {
    int scelta;
    printf("0 Esci\n");
    printf("1 Inserisci il concorrente(pettorale e nome)\n");
    printf("2 Salva i dati(fine giornata)\n");
    printf("3 Carica i dati dal file\n");
    printf("4 Fine Caricamento");
    printf("5 Inserisci i risultati del giorno X\n");
    printf("6 Visualizza tutto\n");
    printf("7 Visualizza vincitore per singola prova\n");
    printf("8 Visualizza classifica\n");
    printf("\nscelta: ");
    scanf("%d\n", &scelta);
    return scelta;
}

void carConc(Atleta t[], int *cont) {
    if(*cont < DIM) {
        printf("inserisci il numero del pettorale: ");
        scanf("%d", &t[*cont].Pettorale);
        printf("inserisci il nome del concorrente: ");
        scanf("%s", t[*cont].Nome);
        (*cont)++;
    }
}

void salvaDati(Atleta t[], int *giorno, int *cont) {
    FILE *fp,*fp1;
    char nomeFile[LUNG];
    printf("inserisci il nome del file dove caricare i dati: ");
    fflush(stdin);
    gets(nomeFile);
    if ((fp = fopen(nomeFile,"r"))!= NULL) {
        if ((fp1 = fopen("temp.txt","w"))!= NULL) {
            while(fscanf(fp,"%d", &*giorno)!= EOF && *giorno < G_MAX) {
                for (int k = 0; k < *cont; k++) {
                    fscanf(fp,"%d", &t[k].Pettorale);
                    fscanf(fp,"%s", t[k].Nome);
                    fprintf(fp1,"%d\n", *giorno);
                    fprintf(fp1,"%d", t[k].Pettorale);
                    fprintf(fp1,"%s", t[k].Nome);
                    for(int j = 0; j < *giorno; j++) {
                        fscanf(fp,"%d", &t[k].Punt[j]);
                        fprintf(fp1,"%d", t[k].Punt[j]);
                    }
                }

            }
        }
        fclose(fp1);
        fclose(fp);
        remove(nomeFile);
        rename("temp.txt",nomeFile);
    }
    (*giorno)++;
}

bool finePiazz() {
    bool finepiazz = true;
    return finepiazz;
}

void carDatiFile(Atleta t[], int *giorno, int *cont) {
    FILE *fp;
    char nomeFile[LUNG];
    printf("inserisci il nome del file da cui prendere i dati: ");
    gets(nomeFile);
    if ((fp = fopen(nomeFile,"r"))!= NULL) {
        while(fscanf(fp,"%d", &*giorno)!= EOF && *giorno < G_MAX) {
            for (int k = 0; k < *cont; k++) {
                fscanf(fp,"%d", &t[k].Pettorale);
                fscanf(fp,"%s", t[k].Nome);
                for(int j = 0; j < *giorno; j++) {
                    fscanf(fp,"%d", &t[k].Punt[j]);
                }
            }
        }
    }
}

void carPiazz(Atleta t[], int *cont) {
    int g;
    printf("di quale giorno vuoi caricare i risultati: ");
    scanf("%d", &g);
    for(int k = 0; k < *cont; k++) {
        printf("inserire il punteggio per l'atleta %s con il pettorale n.%d : ", t[k].Nome, t[k].Pettorale);
        scanf("%d", &t[k].Punt[g]);
    }
}

void visDati(Atleta t[],int *giorno, int*cont) {
    for(int k = 0; k < *cont; k++) {
        printf("%d", t[k].Pettorale);
        printf("%s", t[k].Nome);
        for(int j = 0; j < *giorno; j++) {
            printf("%d", t[k].Punt[j]);
        }
        printf("\n");
    }
}

int main() {

    Atleta tabella[DIM];
    int cont = 0;
    int giorno = 1;
    bool fine;
    int scelta;
    do {
        scelta = menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            if(fine != true){
               carConc(tabella, &cont);
            }else{
            printf("non e' possibile caricare nuovi partecipanti");
            }
            break;
        case 2:
            salvaDati(tabella, &giorno, &cont);
            break;
        case 3:
            carDatiFile(tabella, &giorno, &cont);
            break;
        case 4:
            fine = finePiazz();
            break;
        case 5:
            carPiazz(tabella, &cont);
            break;
        case 6:
            visDati(tabella, &giorno, &cont);
            break;
        case 7:
            break;
        case 8:
            break;
        }

    } while(scelta != 0);
    return 0;
}
