/*
author: Prandi Alessandro
date:
es. 94
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define NR 10
#define NC 5
#define LUNG 20

void inserisciCand(char mat[][LUNG], int r){
    for(int nr = 0; nr < r; nr++) {
        printf("inserisci il nome del %d^ candidato: ", nr + 1);
        fflush(stdin);
        gets(mat[nr]);
    }
}

void scambio(char s1[],char s2[]){
    char nome[LUNG];
    strcpy(nome, s1);
    strcpy(s1, s2);
    strcpy(s2, nome);
}

void bubbleMat(char mat[][LUNG], int nr) {
    int k,sup, sca;
    sup = nr - 1;
    while(sup > 0) {
        sca = 0;
        for (k = 0; k < sup; k++) {
            if (strcmp(mat[k], mat[k + 1]) > 0) {
                scambio(mat[k], mat[k + 1]);
                sca = k;
            }
        }
        sup = sca;
    }
}

void stampaCand(char mat[][LUNG], int r) {
    int nr;
    for(nr = 0; nr < r; nr++) {
        printf("%s\n", mat[nr]);
    }
}

int menu() {
    int scelta;
    printf("\n0 = Esci\n");
    printf("1 = inserisci voti\n");
    printf("2 = Visualizza voti \n");
    printf("3 = work in progress \n");
    printf("scelta: ");
    scanf("%d", &scelta);
}



void caricaVoti(int voto[][NC], int nr, int nc) {
    for(int r = 0; r < nr; r++) {
        for(int c = 0; c < nc; c++) {
            printf("inserisci il %d^ voto del %d candidato: ", c + 1, r + 1);
            scanf("%d", &voto[r][c]);
        }
    }
}

void visualizzaVoti(char mat[][LUNG],int voto[][NC], int nr, int nc) {
    for(int r = 0; r < nr; r++) {
        printf("i voti del candidato %s sono: ", mat[r]);
        for(int c = 0; c < nc; c++) {
            printf("%d ", voto[r][c]);
        }
    }
}


int main() {
    char mat[NR][LUNG];
    int voto[NR][NC];
    bool caricato;
    int scelta;

    inserisciCand(mat, NR);
    bubbleMat(mat, NR);
    stampaCand(mat, NR);

    do {
        scelta = menu();

        switch(scelta) {
        case 0:
            break;
        case 1:
            caricato= true;
            caricaVoti(voto, NR, NC);
            break;
        case 2:
            if(caricato == true) {
                visualizzaVoti(mat, voto, NR, NC);
            } else {
                printf("\nprima inserire i voti");
            }
            break;
        case 3:

            break;
        }

    } while(scelta != 0);

    return 0;
}
