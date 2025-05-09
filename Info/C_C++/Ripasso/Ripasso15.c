#include <stdio.h>
#include <stdlib.h>
#define MAX 10

void scambio(float *n1, float *n2) {
    float z;
    z = *n1;
    *n1 = *n2;
    *n2 = z;
}

float Min(float vett[], int n) {
    float minimo;
    for (int i = 0; i < n; i) {
        minimo = vett[0];
        if (vett[i] < minimo) {
            minimo = vett[i];
        }
    }
    return minimo;
}

float Max(float vett[], int n) {
    float massimo;
    for (int i = 0; i < n; i) {
        massimo = vett[0];
        if (massimo < vett[i]) {
            massimo = vett[i];
        }
    }
    return massimo;
}

void Decrescenti(float vett[], int n) {
    int sup, sca;
    sup = n - 1;
    while (sup > 0) {
        sca = 0;
        for (int k = 0; k < sup; k++) {
            if (vett[k] < vett[k + 1]) {
                scambio(&vett[k], &vett[k + 1]);
                sca = k;
            }
        }
        sup = sca;
    }
}

int main() {
    float vett[MAX], max, min;
    int dim;
    printf("quanti numeri vuoi ordinare: ");
    scanf("%d", &dim);
    for (int j = 0; j < dim; j++) {
        printf("inserisci un numero: ");
        scanf("%f", &vett[j]);
    }

    min = Min(vett, dim);
    printf("il minimo è: %.2f \n", min);
    max = Max(vett, dim);
    printf("il massimo è: %.2f", max);
    Decrescenti(vett, dim);
    printf("numeri ordinati:");
    for (int j = 0; j < dim; j++) {
        printf(" %.2f", vett[j]);
    }

    return 0;
}
