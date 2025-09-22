/*
author: Prandi Alessandro
date: 29/03/2023
es. verifica2
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIM 35

void CaricaDati(float alt[], int n) {
    for (int k = 0; k < n; k++) {
        printf("inserisci l'altezza dell'alunno[%d]: ", k);
        scanf("%f", &alt[k]);
    }
}

int chiediDim(int dim_Max) {
    int x;
    do {
        printf("inserisci la dimensione del vettore[0...%d]: ",dim_Max);
        scanf("%d", &x);
    } while(x < 0 || x > dim_Max);
    return x;
}

void scambio(float *x, float *y) {
    float z;
    z = *x;
    *x = *y;
    *y = z;
}

void bubbleSort3(float v[], int n) {
    int sup,sca;
    sup = n;
    while(sup > 0) {
        sca = 0;
        for(int k = 0; k < sup-1; k++) {
            if(v[k] < v[k + 1]) {
                scambio(&v[k + 1], &v[k]);
                sca = k;
            }
        }
        sup = sca;
    }
}

float mediana(float v[],int n) {
    float ris,v1,v2;
    if(n % 2 == 0) {
        v1 = v[n/2 + 1];
        v2 = v[n/2];
        ris = v1 + v2;
    } else
        ris = v[n/2];
    return ris;
}

float ordNonDisg(float v[], int n, float x) {
    int tro,k,nx;
    k = 0;
    nx = 0;
    tro = -1;
    while(k < n && tro == -1) {
        if(v[k] == x) {
            nx++;
        } else if(v[k] < x) {
            tro = k;
        }
        k++;
    }
}

float minMax(float v[], int n) {
    int val;
    val = v[n];
    return val;
}
float minore(int min) {
    float alt;
    do {
        scanf("%f", &alt);
    } while(alt < min);
    return min;
}

int main() {
    float vett[DIM];
    int dim = chiediDim(DIM);
    float max,min,cerca,med;
    int npers;

    CaricaDati(vett, dim);
    bubbleSort3(vett, dim);

    max = minMax(vett, 0);
    min = minMax(vett, dim-1);

    printf("l'altezza maggiore è %.2f", max);
    printf("l'altezza minore è %.2f", min);

    med = mediana(vett, dim);
    printf("la mediana è %.2f", med);

    printf("quale altezza vuoi cercare?");
    cerca = minore(0);

    npers = ordNonDisg(vett, dim, cerca);
    printf("sono presenti %d alte %.2f m", npers, cerca);
    return 0;
}
