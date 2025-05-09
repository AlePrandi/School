/*
author: Prandi Alessandro
date: 17/04/2023
esercizio: 58
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <math.h>

#define MAXR 5
#define MAXC 7
#define LUNG 100


int chiediDim(int dim_max, char msg[]) {
    int dim;
    printf("%s", msg);
    do {
        printf(" tra [0 e %d] ", dim_max);
        scanf("%d", &dim);
    } while (dim < 0 || dim > dim_max);
    return dim;
}

int menu() {
    int scelta;
    printf("\n0 = Esci\n");
    printf("1 = Carica voti di un alunno (scritto, orale e pratico), il nome e calcola la media\n");
    printf("2 = Visualizza gli insufficienti \n");
    printf("3 = Visualizza il più bravo/i (Quello/i con la media maggiore, ci possono essere parimerito) \n");
    printf("4 = Sono tutti sufficienti??? \n");
    printf("5 = Data un nome cambiare i suoi voti\n");
    printf("6 = ordinare in base al nome e visualizzare tutti i dati\n");
    printf("7 = ordinare in ordine decrescente di media e visualizzare tutti i dati\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

void leggiVoti(char alunni[], float vs[],float vo[], float vp[],float media[],int n) {

    for(int k = 0;k < n; k++){
    printf("inserisci il nome dell'alunno ");
    fflush(stdin);
    scanf("%s", alunni[k]);
    printf("inserisci il voto scritto: ");
    scanf("%f", &vs[k]);
    printf("inserisci il voto orale: ");
    scanf("%f", &vo[k]);
    printf("inserisci il voto pratico: ");
    scanf("%f", &vp[k]);


    media[k]=(vs[k]+vo[k]+vp[k])/3;
    printf("l'alunno %s ha la media dei voti pari a %.2f\n", alunni[k], media[k]);
    }


}

void verificaSuf(char alunni[][LUNG], float mat[][MAXC], int nr, int nc) {
    int ins=0;
    for(int r=0; r<nr; r++) {
            if(mat[r][3] < 6) {
                ins=ins+1;
                printf("l'alunno %s e' insufficente\n", alunni[r]);
            }
    }
    printf("gli insufficenti sono %d\n", ins);
}

void mediaMax(char alunni[][LUNG], float mat[][MAXC], int nr, int nc){
        float max = mat[0][3];
    for(int r=0; r<nr; r++) {
            if(mat[r][3] > max){
                    max = mat[r][3];
                    printf("l'alunno con la media piu' alta e: %s", alunni[r]);
            }

    }
}

int main() {

    int n=chiediDim(MAXR, "quanti alunni al massimo");
    int scelta;
    char alunni[LUNG];
    float voti[LUNG];
    float votiOrali[LUNG];
    float votiScritti[LUNG];
    float votiPratico[LUNG];
    float media=0;
    int ins=0;
    int r=0;

    do {
        scelta=menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            leggiVoti(alunni,);
            break;
        case 2:
            verificaSuf(alunni, voti, n, 3);
            break;
        case 3:
            mediaMax(alunni, voti, n, 3);
            break;
        case 4:

            break;
        case 5:

            break;
        case 6:

            break;
        case 7:

            break;
        }
    } while(scelta!=0);
}

