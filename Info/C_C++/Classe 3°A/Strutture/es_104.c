/*
author: Prandi Alessandro
date:14/05/2023
es. 104
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 20
#define DIM 6

typedef struct {
    char nome_squadra[LUNG];
    int cod_squadra;
    int gol_fatti;
    int gol_subiti;
} Squadra;

int CaricaCamp(Squadra s[]) {
    char nomeFile[LUNG] = "campionato.dat";
    FILE *fp;
    int nSquad = 0;

    fp=fopen(nomeFile, "r");
    if(fp == NULL) {
        printf("il file %s non esiste\n", nomeFile);
    } else {
        while(nSquad < DIM && fscanf(fp, "%s", s[nSquad].nome_squadra)!= EOF) {
            fscanf(fp, "%d", &s[nSquad].cod_squadra);
            fscanf(fp, "%d", &s[nSquad].gol_fatti);
            fscanf(fp, "%d", &s[nSquad].gol_subiti);
        }
        nSquad ++;
    }
    fclose(fp);
    return nSquad;
}

int menu(){
    int scelta;
    printf("0 Esci\n");
    printf("1 Visualizza squadre in ordine alfabetico\n");
    printf("2 Visualizza squadre con diff. punti positiva \n");
    printf("3 Cerca una squadra tramite codice\n");
    scanf("%d", &scelta);
    return scelta;
}

void vis_Diff_Pos(Squadra campionato[], int n_squadre) {
    Squadra Ord_Pos[DIM];
    int s_poss=0;
    for(int k=0; k<n_squadre; k++) {
        if(campionato[k].gol_fatti > campionato[k].gol_subiti) {
            Ord_Pos[k].cod_squadra = campionato[k].cod_squadra;
            strcpy(Ord_Pos[k].nome_squadra,campionato[k].nome_squadra);
            s_poss++;
        }
    }
    for(int j=0; j<s_poss; j++) {
        printf("Nome squadra: %s Codice squadra: %d \n",Ord_Pos[j].nome_squadra,Ord_Pos[j].cod_squadra);
    }
}

void Ric_Cod_Squadra(Squadra campionato[], int n_squadre) {
    int k;
    int codice;
    bool epres=false;
    printf("Inserire il codice della squadra da cercare: \n");
    scanf("%d",&codice);
    while(k<n_squadre && epres==false) {
        if(codice==campionato[k].cod_squadra) {
            printf("Squadra trovata! \n");
            printf("Nome squadra: %s \n",campionato[k].nome_squadra);
            printf("Gol fatti: %d \n",campionato[k].gol_fatti);
            printf("Gol subiti: %d \n",campionato[k].gol_subiti);
            epres=true;
        } else {
            k++;
        }
    }
    if(epres==false) {
        printf("Squadra non presente! \n");
    }
}

void scambio(Squadra c1[],Squadra c2[]) {
    Squadra *c3;
    c3 = c1;
    c1 = c2;
    c2 = c3;
}

void Ordina_Strutt(Squadra campionato[], int n) {
    int k,sup,sca;
    sup=n - 1;
    while (sup > 0) {
        sca = 0;
        for (k = 0; k < sup ; k++) {
            if (campionato[k].nome_squadra > campionato[k+1].nome_squadra) {
                scambio(&campionato[k],&campionato[k+1]);
                sca = k;
            }
        }
        sup=sca ;
    }
}

int main() {
    Squadra campionato[DIM];
    int n_squadre;
    char nomeFile[LUNG]="campionato.txt";
    n_squadre=CaricaCamp(campionato);
    int scelta;
    do {
        scelta = menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            Ordina_Strutt(campionato,n_squadre);
            break;
        case 2:
            vis_Diff_Pos(campionato,n_squadre);
            break;
        case 3:
            Ric_Cod_Squadra(campionato,n_squadre);
            break;
        }
    } while(scelta!=0);
return 0;
}
