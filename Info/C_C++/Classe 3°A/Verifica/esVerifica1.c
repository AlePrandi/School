/*
author: Prandi Alessandro
date: 03/05/2023
es. verifica1
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NUM_PART 4
#define LUNG 30
#define DIM 100


int chiediDim(int dim_max, char msg[]) {
    int dim;
    printf("%s", msg);
    do {
        printf(" tra [0 e %d]: ", dim_max);
        scanf("%d", &dim);
    } while (dim < 0 || dim > dim_max);
    return dim;
}

void caricaPunt(char Nome[][LUNG], int Punt[][NUM_PART], int nr, int nc) {
    for(int r = 0; r < nr; r++) {
        printf("[%d]inserisci il nome del giocatore: ", r + 1);
        fflush(stdin);
        gets(Nome[r]);
        for(int c = 0; c < nc; c++) {
            do {
                printf("inserisci il %d^ punteggio della %d partita per il giocatore %s: ",c + 1, r + 1, Nome[r]);
                scanf("%d", &Punt[r][c]);
            } while(Punt[r][c] < 0);
        }
    }
}

void scambioPunt(int p1[], int p2[]) {
    int temp;
    temp = p1;
    p1 = p2;
    p2 = temp;
}

void scambioNome(char s1[],char s2[]) {
    char nome[LUNG];
    strcpy(nome, s1);
    strcpy(s1, s2);
    strcpy(s2, nome);
}

void bubblePunt(char Nome[][LUNG],int Punt[],int nr) {
    int k,sup, sca;
    sup = nr - 1;
    while(sup > 0) {
        sca = 0;
        for (k = 0; k < sup; k++) {
            if (Punt[k] > Punt[k + 1]) {
                scambioPunt(Punt[k], Punt[k + 1]);
                scambioNome(Nome[k], Nome[k + 1]);
                sca = k;
            }
        }
        sup = sca;
    }
}

void Podio(char Nome[][LUNG], int Punt[][NUM_PART], int nr, int nc) {
    int som_somme[nr];
    int somma;
    for(int r = 0; r < nr; r++) {
        somma = 0;
        for(int c = 0; c < nc; c++) {
            somma = somma + Punt[r][c];
        }
        som_somme[nr] = somma;
    }
    bubblePunt(Nome,som_somme, nr);
    printf("\nil giocatore %s è arrivato primo con %d punti", Nome[1], som_somme[1]);
    printf("\nil giocatore %s è arrivato secondo con %d punti", Nome[2], som_somme[2]);
    printf("\nil giocatore %s è arrivato terzo con %d punti", Nome[3], som_somme[3]);
}

void CercaGioc(char Nome[][LUNG], int Punt[][NUM_PART], int nr, int nc, char Ricerca[LUNG]) {
    int nx;
    nx=0;
    for(int r = 0; r < nr; r++) {
        if(Nome[r] == Ricerca) {
            printf("giocatore trovato, i suoi punteggi sono: ");
            nx++;
        }
        for(int c = 0; c < nc; c++) {
            printf("%d ", Punt[r][c]);
        }
    }
    if(nx == 0) {
        printf("il giocatore non è nell' elenco");
    }
}

void AggiornaDati(char Nome[][LUNG], int Punt[][NUM_PART], int nr, int nc, char Ricerca[LUNG]) {
    for(int r = 0; r < nr; r++) {
        if(Nome[r] == Ricerca) {
            for(int c = 0; c < nc; c++) {
                do {
                    printf("inserisci il %d^ punteggio della %d partita per il giocatore %s: ",c + 1, r + 1, Nome[r]);
                    scanf("%d", &Punt[r][c]);
                } while(Punt[r][c] < 0);
            }
        }
    }
}

int menu() {
    int scelta;
    printf("\n0 = Esci\n");
    printf("1 = Visualizza Podio\n");
    printf("2 = Cerca Nome Giocatore\n");
    printf("3 = Aggiorna Dati\n");
    printf("scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

int main() {
    int num_Gioc,scelta;
    num_Gioc = chiediDim(DIM, "inserisci il numero di giocatori");
    int Punt_Gioc[num_Gioc][NUM_PART];
    char Nome_gioc[num_Gioc][LUNG];
    char Nome_Ric[LUNG];
    caricaPunt(Nome_gioc, Punt_Gioc, num_Gioc, NUM_PART);

    do {
        scelta = menu();

        switch(scelta) {
        case 0:
            break;

        case 1:
            Podio(Nome_gioc, Punt_Gioc, num_Gioc, NUM_PART);
            break;

        case 2:
            printf("quale giocatore vuoi cercare: ");
            fflush(stdin);
            gets(Nome_Ric);
            CercaGioc(Nome_gioc, Punt_Gioc, num_Gioc, NUM_PART, Nome_Ric);

        case 3:
            printf("i dati di quale giocatore vuoi aggiornare: ");
            fflush(stdin);
            gets(Nome_Ric);
            AggiornaDati(Nome_gioc, Punt_Gioc, num_Gioc, NUM_PART, Nome_Ric);
        }
    } while(scelta != 0);
    return 0;
}
