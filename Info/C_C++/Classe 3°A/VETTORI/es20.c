/*
author: Prandi Alessandro
date: 01/03/2023
es. 20
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>
#define DIM 100
#define MIN -20
#define MAX 20

int ScegliDim(int n) {
    int x;
    do {
        printf("Inserisci la dimensione del vettore: \n");
        scanf("%d", &x);
    } while(x<0 || x>n);
    return x;
}

void caricaVettCasuali(int v[], int n) {
    srand(time(NULL));

    for(int k = 0; k < n; k++) {
        v[k] = MIN + rand() % (MAX + 1 - MIN);
    }
}

void stampaVett(int v[], int n) {
    for(int k=0; k<n; k++) {
        printf("%d ", v[k]);
    }
}

void sommaVett(int v[], int n, int *somma) {
    *somma = 0;
    for(int k=0; k<n; k++) {
        *somma = *somma + v[k];
    }
    printf("la somma e: %d\n", somma);
}

void mediaVett(int v[], int n, int *somma, float *media) {
    if(n != 0){
        *media = (float) *somma / n;
    printf("la media e: %.2f\n", media);
    }else
    printf("\nmedia non possibile");
}

bool pos(int v[], int n){
    bool tuttiPos = true;
    int k = 0;
    while (k < n && tuttiPos == true){
        if (v[k] <= 0)
            tuttiPos = false;
}return tuttiPos;
}

int menu() {

    int scelta;
    printf("0 = Esci\n");
    printf("1 = Carica Vett casuale \n");
    printf("2 = Stampa Vettore\n");
    printf("3 = Somma di tutti gli elementi\n");
    printf("4 = Media di tutti gli elementi\n");
    printf("Scelta: ");
    scanf("%d", &scelta);
    return scelta;
}

int main() {

    int scelta, somma;
    float media;
    int vett[DIM];
    int dim = 0;

    do {
        scelta=menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            dim = ScegliDim(DIM);
            caricaVettCasuali(vett,dim);
            stampaVett(vett, dim);
            printf("\n");
            break;
        case 2:
            dim = ScegliDim(DIM);
            stampaVett(vett, dim);
            break;
        case 3:
            dim = ScegliDim(DIM);
            sommaVett(vett, dim, &somma);
            break;
        case 4:
            dim = ScegliDim(DIM);
            sommaVett(vett, dim, &somma);
            mediaVett(vett, dim, &somma, &media);
            break;
        }
    } while(scelta!=0);

    return 0;
}
