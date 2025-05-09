/*
author: Prandi Alessandro
date: 26/02/2023
es. 15
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 100

int chiediDim(int dim_Max) {
    int dim;
    do {
        printf("Inserisci un valore per la dimensione: ");
        scanf("%d", &dim);
    } while(dim < 0 || dim > dim_Max);
    return dim;
}

void caricaVett(float v[], int dim) {
    for(int k=0; k<dim; k++) {
        printf("Inserisci un numero:\n");
        scanf("%f", &v[k]);
    }
}

void sommaVett(float v[], int n, int ris) {
/*
        float x;
        float y;
*/
    for (int k = 0; k < n; k++) {
       /* if(k == 0) {
            x = v[k];
            y = v[k + 1];
        }
        else{
         v[k] = v[k + 1] + v[k + 2];

        if (k == n) {
            v[k] = x + y;
        }
        }*/
        ris = v[k] + v[(k + 1) % n] + v[(k + 2) % n];
    }
}

void stampaVett(float ris, int n) {
    for (int k = 0; k < n; k++) {
        printf("%.2f", ris);
    }
}

int main() {
    float vettA[DIM];
    int neUso = 5;
    int ris;

    caricaVett(vettA, neUso);

    sommaVett(vettA, neUso, ris);

    stampaVett(ris, neUso);
    return 0;
}
