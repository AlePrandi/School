/*
author: Prandi Alessandro
date: 29/05/2023
es. 112
testo:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 30
#define DIM 3

typedef struct {
    char tipo[LUNG];
    int eta_media;
    int stipendio_medio;
    int n_persone;
} Lavoratore;

int menu() {
    int scelta;
    printf("0 per uscire: \n");
    printf("1 per inserire nuovo lavoratore \n");
    printf("2 per visualizzare un tipo \n");
    printf("3 per visualizzare tutto \n");
    printf("Scelta: ");
    scanf("%d",&scelta);
    return scelta;
}

void inserisciLav(Lavoratore dipendente[]){
    int eta;
    int stipendio;
    char nome[LUNG];
    bool tro=false;
    printf("Inserire il lavoro: \n");
    fflush(stdin);
    gets(nome);
    int j=0;
    while(tro==false && j<DIM) {
        if(strcmp(nome,dipendente[j].tipo)>0) {
            strcpy(dipendente[j].tipo,nome);
            printf("Inserire l'eta': \n");
            scanf("%d",&eta);
            dipendente[j].eta_media = (dipendente[j].eta_media * (dipendente[j].n_persone - 1)) + eta / dipendente[j].n_persone;
            printf("Inserire lo stipendio: \n");
            scanf("%d",&stipendio);
            dipendente[j].stipendio_medio=(dipendente[j].stipendio_medio+stipendio)/(dipendente[j].n_persone+1);
            dipendente[j].n_persone=dipendente[j].n_persone+1;
            tro=true;
        } else {
            strcpy(dipendente[j].tipo,nome);
            printf("Inserire l'eta': \n");
            scanf("%d",&eta);
            dipendente[j].eta_media=(dipendente[j].eta_media+eta)/(dipendente[j].n_persone+1);
            printf("Inserire lo stipendio: \n");
            scanf("%d",&stipendio);
            dipendente[j].stipendio_medio=(dipendente[j].stipendio_medio+stipendio)/(dipendente[j].n_persone+1);
            dipendente[j].n_persone++;
            j++;
        }
    }
}

void visTipo(Lavoratore dipendente[]) {
    char nome[LUNG];
    printf("Inserire il lavoro dove visualizzare i dati \n");
    gets(nome);
    bool tro=false;
    int k=0;
    while(tro==false) {
        if(strcmp(nome,dipendente[k].tipo)>0) {
            printf("Tipo: %s",dipendente[k].tipo);
            printf("Eta media: %d",dipendente[k].eta_media);
            printf("Stipendio medio: %d",dipendente[k].stipendio_medio);
            printf("Numero lavoratori: %d",dipendente[k].n_persone);
            tro=true;
        } else {
            k++;
        }
    }
    if(tro==false) {
        printf("Non esiste il tipo di lavoratore \n");
    }
}

void visTutto(Lavoratore dipendente[]) {
    for(int k=0; k<DIM; k++) {
        printf("Tipo: %s",dipendente[k].tipo);
        printf("Eta media: %d",dipendente[k].eta_media);
        printf("Stipendio medio: %d",dipendente[k].stipendio_medio);
        printf("Numero lavoratori: %d",dipendente[k].n_persone);
    }
}

int main() {
    Lavoratore dipendente[DIM];
    int scelta;
    do {
        scelta=menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            inserisciLav(dipendente);
            break;
        case 2:
            visTipo(dipendente);
            break;
        case 3:
            visTutto(dipendente);
            break;
        }
    }while(scelta!=0);
}
