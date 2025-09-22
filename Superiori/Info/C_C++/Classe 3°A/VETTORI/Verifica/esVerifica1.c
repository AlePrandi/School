/*
author: Prandi Alessandro
date: 29/03/2023
es. verifica1
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define N 5

bool eVerificato(int vett[], int n) {
    int k;
    bool uguali = true;
    k = 0;
    while(k < n && uguali == true) {
        if(k % 2 == 0) {
            if(vett[k] % 2 != 0) {
                uguali = false;
            }
        } else if(vett[k] % 2 == 0) {
            uguali = false;
        }
         k++;
    }
    return uguali;
}

int main() {
    int vettore[N] = {10, 1, 12, 31, 0};

    if (eVerificato(vettore, N) == true) {
        printf("i vettori sono tutti giusti");
    } else
        printf("i vettori non sono tutti giusti");
    return 0;
}
