/*
author: Prandi Alessandro
date:10/05/2023
es. 103
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 21
#define LUNG 100

typedef struct {
char nome_corso[LUNG];
char nome_docente[LUNG];
int n_iscritti;
}Corso;

int leggiCorsi(char nomeFile[],Corso corsi[], int max_corsi){
    FILE*fp;
    int n_corsi=0;
    fp = fopen(nomeFile,"r");
    if(fp==NULL){
        printf("file non esistente");
    }else{
        while(n_corsi < max_corsi && fscanf(fp, "%s %s %d"),corsi[n_corsi].nome_corso,corsi[n_corsi].nome_docente,&corsi[n_corsi].n_iscritti){
            n_corsi++;
        }
    }
    fclose(fp);
    return n_corsi;
}

int calcolaMedia(Corso corsi[], int n_corsi){
    int somma=0;
    int media;
    for(int k=0;k<n_corsi;k++){
        somma=somma+corsi[k].n_iscritti;
    }
    media=somma/n_corsi;
    return media;
}

void visCorsi(Corso corsi[], int n_corsi, int media){
    for(int k=0;k<n_corsi;k++){
        if(corsi[k].n_iscritti>media){
            printf("Nome corso: %s",corsi[k].nome_corso);
            printf("Nome docente: %s",corsi[k].nome_docente);
        }
    }
}

void stampaMaggiore(Corso corsi[], int n_corsi){
    int magg=0; //posizione
    for(int k=1;k<n_corsi;k++){
        if(corsi[magg].n_iscritti>corsi[k].n_iscritti){

        }
        else{
            magg=k;
        }
    }
    printf("Corso con piu' iscritti: %s %s %d",corsi[magg].nome_corso,corsi[magg].nome_docente,corsi[magg].n_iscritti);
}

int main(){
    Corso corsi[DIM];
    Corso maggiore[DIM];
    int n_corsi;
    int media;
    char nomeFile[LUNG]="corsi.txt";
    leggiCorsi(nomeFile,corsi,DIM);
    media = calcolaMedia(corsi,n_corsi);
    visCorsi(corsi,n_corsi,media);
    stampaMaggiore(corsi,n_corsi);
}
