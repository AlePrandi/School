/*
author: Alessandro Prandi
date: 23/05/2023
es.108

{"KettImport",{90,93,99,95,102,93,101}},
{"ACME", {100,95,100,88,60,105,107}},
{"Grassi", {99,92,97,91,102,98,103}},
{"ASDF", {94,103,96,100,90,80,99}},
{"Lanzi", {102,93,102,92,101,94,100}}
*/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define LUNG 20
#define NGIORNI 7
#define DIM 100
#define PERC 10

typedef struct {
    char nome[LUNG];
    float valori[NGIORNI];
} Quotazione;

void caricaVett(Quotazione vett[], int n, int giorni) {
    for(int k=0; k<n; k++) {
        printf("Inserisci il nome dell'azienda[%d]: ", k+1);
        fflush(stdin);
        scanf("%s", vett[k].nome);
        for(int i=0; i<giorni; i++) {
            printf("inserire il valore del giorno [%d]: ", i+1);
            scanf("%f", &vett[k].valori[i]);
        }
    }
}

void visAzioni(Quotazione vett[], int n, int giorni) {
    for(int k=0; k<n; k++) {
        printf("%s\t", vett[k].nome);
        for(int i=0; i<giorni; i++) {
            printf("%.2f\t", vett[k].valori[i]);
        }
        printf("\n");
    }
}

int caloAzioni(Quotazione vett[], int n, int giorni) {
    int cont;
    int n_aziende=0;
    for(int k=0; k<n; k++) {
        cont =0;
        int i=1;
        while(i<giorni && cont == 0) {
            float q;
            q= vett[k].valori[i-1] * PERC / 100;
            if(vett[k].valori[i] < vett[k].valori[i-1]-q) {
                cont++;
            }
            i++;
        }
        if(cont != 0) {
            n_aziende++;
            printf("l'azienda %s ha avuto cali maggiori del %d%%\n", vett[k].nome, PERC);
        }
    }
    return n_aziende;
}

int chiediDim(int dimMax) {
    int x;
    do {
        printf("inserire il numero di aziende: ");
        scanf("%d", &x);
    } while(x<0||x>dimMax);
    return x;
}

int caricaFile(char nomeFile[], Quotazione vett[], int nmax, int giorni) {
    int n=0;
    FILE *fp;

    fp= fopen(nomeFile, "r");
    if(fp==NULL) {
        printf("file non trovato\n");
    } else {
        while(n<nmax && fscanf(fp, "%s", vett[n].nome) != EOF) {
            for(int k=0; k<giorni; k++) {
                fscanf(fp, "%f", &vett[n].valori[k]);
            }
            n++;
        }
        fclose(fp);
    }
    return n;
}

void minGiorno(Quotazione vett[], int nmax, int giorni) {
    FILE *fp;
    float min;
    int nomeMin = 0;
    char file[LUNG] = "minimi.txt";
    fp= fopen(file, "w");
    if(fp==NULL) {
        printf("file non trovato\n");
    } else {
        for(int k = 0; k < giorni; k++){
            for (int j = 0; j < nmax; j++){
                if(j == 0 || vett[j].valori[k] < min){
                    min = vett[j].valori[k];
                    nomeMin = j;
                }
            }
            fprintf(fp,"la quotazione minore del giorno %d e' stata %s con un valore di %.2f \n", k, vett[nomeMin].nome, min);
        }
    }
    }

    int main() {
        Quotazione vett[DIM];
        //int dim=chiediDim(DIM);
        char nomeFile[LUNG]= "quote.txt";
        int dim=caricaFile(nomeFile, vett, DIM, NGIORNI);


        //caricaVett(vett, dim, NGIORNI);
        visAzioni(vett, dim, NGIORNI);
        int n_aziende=caloAzioni(vett, dim, NGIORNI);
        printf("le aziende che hanno avuto un calo maggiore di [%d%%] sono: %d\n", PERC, n_aziende);
        minGiorno(vett, dim, NGIORNI);
        return 0;
    }
