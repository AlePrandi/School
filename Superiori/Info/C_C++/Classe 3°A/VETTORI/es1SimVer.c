/*
author: Prandi Alessandro
date:
es.
testo
creare la funzione che dato un vettore ad interi e
un umero x indichi se sono tutti multipli di x
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DIM 4

bool cercaMult(int v[],int n, int x) {
    int k;
    bool mult = true;
    while (k < n && mult == true) {
        if (v[k] % x != 0)
            mult = false;
        else
            k++;
    }
    return mult;
}

int main() {
    int vett[DIM]= {1, 2, 3, 4};
    int x;

    return 0;
}


/*
ad una gara con tre prove sono iscritti 15 concorrenti,
caricare per ogni concorrenti il numero di pettorina e le prove 0 se il salto è nullo.
creare il vettore max che trova il valore massimo per ciacun concorrente.
stilare la classifica e calcolare quanti salti sono nulli
*/

void caricaDati(int pett[], float prova1[],float prova2[], float prova3[], int n) {
    for(int k = 0; k < n; k++) {
        printf("[%d]inserisci il numero di pettorale: ", k);
        scanf("%d", &pett[k]);
        printf("[%d]inserisci il valore della prima prova: ", k);
        scanf("%f", &prova1[k]);
        printf("[%d]inserisci il valore della seconda prova: ", k);
        scanf("%f", &prova2[k]);
        printf("[%d]inserisci il valore della terza prova: ", k);
        scanf("%f", &prova3[k]);
    }

}

void trovaMax(int pett[], float prova1[],float prova2[], float prova3[], int n, float max[]) {
    for(int k = 0; k < n; k++) {
        if(prova1[k] > max[k])
            max[k] = prova1[k];
        if(prova2[k] > max[k])
            max[k] = prova2[k];
        if(prova3[k] > max[k])
            max[k] = prova3[k];
    }
}

void scambio(int)

void ordinaMax(float max[], int n){
int k;
k = 0;
while(k < n ){
    if(max[k] > max[k + 1]){
        scambio(&max[k], &max[k + 1]);
    }
}
}
