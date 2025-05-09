/*
author: Prandi Alessandro
date: 02/01/2023
es. verifica
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

float inputMaggioredi(float num) {
    float n;
    do {
        printf("inserisci un numero maggiore di %.2f", num);
        scanf("%f", &n);
    } while(n < num);
    return n;
}

bool eTriplo(float n1, float n2) {
    bool triplo;
    if (n1 == n2 * 3)
        triplo = true;
    else
        triplo = false;
    return triplo;
}

float altezza(float l) {
    float alt;
    alt = sqrt(l * l - (l * l) / 2);
    return alt;
}
void perimetroAreaTriangolo(float l) {
    float area,perim,alt;
    alt = altezza(l);
    area = (l / 2) * alt;
    perim = l * 3;
    printf("l'area e %.2f\n", area);
    printf("il perimetro e %.2f\n", perim);
    return;
}
int main() {
    float l1,l2,h1,h2;

    printf("inserisci il primo lato: ");
    l1 = inputMaggioredi(0);
    printf("inserisci il secondo lato: ");
    l2 = inputMaggioredi(0);
    h1 = altezza(l1);
    h2 = altezza(l2);
    if (eTriplo(h1, h2/2) == true) {
        printf("i triangoli sono in armonia\n");
        perimetroAreaTriangolo(l1);
        printf("\n");
        perimetroAreaTriangolo(l2);
    } else
        printf("\nnon sono in armonia");
    perimetroAreaTriangolo(l1);
    printf("\n");
    perimetroAreaTriangolo(l2);
}
