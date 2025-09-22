/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include "vettori.h"
#define DIM 5

void shiftVett(int v[], int n) {
    int ultimo = v[n - 1];
    for (int k = 0; k < n; k++) {
        v[k] = v[k - 1];
    }
    v[0]= ultimo;
}

int main() {
    int vett[DIM] = {1, 2, 3, 4};
    shiftVett(vett, DIM);
    stampaVett(vett, DIM);

    return 0;
}
