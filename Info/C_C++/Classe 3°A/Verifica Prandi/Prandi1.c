/*
autor: Prandi Alessandro
es. 2
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define LUNG 31
#define MAX_SQUADRE 25
#define GIORNI_MAX 4

typedef struct {
    char nome[LUNG];
    int punti[GIORNI_MAX];
    int pTot;
} Squadra;

int CaricaDati(Squadra s[], int giorni, int max_squad) {
    int n = 0;
    char nomeFile[LUNG] = "squadre.dat";
    FILE *fp;
    fp = fopen(nomeFile, "r");
    if (fp == NULL) {
        printf("il file non esiste");
    } else {
        while(n < max_squad && fscanf(fp, "%s", s[n].nome) != EOF) {
            s[n].pTot = 0;
            for(int g = 0; g < giorni; g++) {
                fscanf(fp,"%d", s[n].punti[g]);
                s[n].pTot = s[n].pTot + s[n].punti[g];
            }
            n++;
        }
    }fclose(fp);
    return n;
}

void VisDati(Squadra s[], int giorni, int n_squad) {
    int g,squad;
    for(squad = 0; squad < n_squad; squad++) {
        printf("%s ", s[squad].nome);
        for(g = 0; g < giorni; g++) {
            printf(" %d ", s[squad].punti[g]);
        }
        printf("%d ", s[squad].pTot);
    }
}

void CercaSquad(Squadra s[], int giorni, int n_squad, char cerca[LUNG]) {
    int g_cerc;
    int n = 0;
    int tro = -1;
    while(n < n_squad && tro == -1) {
        if (strcmp(s[n].nome, cerca) == 0) {
            tro = n;
            do {
                printf(" inserisci la giornata in cui vuoi caricare il punteggio: ");
                scanf("%d", &g_cerc);
            } while (g_cerc < 0 || g_cerc > giorni - 1);
            printf("inserisci il nuovo punteggio: ");
            scanf("%d", &s[n].punti[g_cerc - 1]);
        }
    }
}

void scambio(Squadra *s1, Squadra *s2) {
    Squadra s3;
    s3 = *s1;
    *s1 = *s2;
    *s2 = s3;
}

void OrdinaStrutt(Squadra s[], int n_squad) {
    int k, sup, sca;
    sup = n_squad - 1;
    while (sup > 0) {
        sca = 0;
        for(k = 0; k < sup; k++) {
            if(s[k].pTot < s[k + 1].pTot) {
                if(s[k].pTot == s[k + 1].pTot) {
                    if(strcmp(s[k].nome,s[k].nome) == -1) {
                        scambio(&s[k], &s[k + 1]);
                    }
                } else
                    scambio(&s[k], &s[k + 1]);
                sca = k;
            }
        }
        sup = sca;
    }
}

void Classifica(Squadra s[], int giorni, int n_squad) {
    int max[MAX_SQUADRE];
    char smax[MAX_SQUADRE][LUNG];
    FILE *fp;
    fp = fopen("campionato.dat", "w");
    fprintf(fp,">>Vincitori della Giornata\n");
    for(int g = 0; g < giorni; g++) {
        fprintf(fp,"Giornata %d: ", g + 1);
        for(int squad = 0; squad < n_squad; squad++) {
            if(g == 0) {
                max[g] = s[squad].punti[g];
            }
            if(s[squad].punti[g] > max[g]) {
                max[g] = s[squad].punti[g];
                fprintf(fp,"%s", s[squad].nome);
            }
        }
    }
    OrdinaStrutt(s, n_squad);
    fprintf(fp,">>Classifica finale");
    for(int k = 0; k < n_squad; k++) {
        fprintf(fp,"%s %d", s[k].nome, s[k].pTot);
        fprintf(fp,"\n");
    }
    fclose(fp);
}

int main(){
    int n_squadre;
    char nome_squad[LUNG];
    Squadra Campionato[MAX_SQUADRE];

    n_squadre = CaricaDati(Campionato, GIORNI_MAX, MAX_SQUADRE);
    VisDati(Campionato, GIORNI_MAX, n_squadre);

    printf("inserisci la squadra da cercare: ");
    fflush(stdin);
    gets(nome_squad);
    CercaSquad(Campionato, GIORNI_MAX, n_squadre, nome_squad);
    Classifica(Campionato, GIORNI_MAX, n_squadre);

    return 0;
}
