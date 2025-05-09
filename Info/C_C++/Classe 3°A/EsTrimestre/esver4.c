/*
author: Prandi Alessandro
date: 13/02/2023
es. ver4
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool ePerf(int x, int *ris) {
    int r;
    int d = 1;
    int divTot = 0;
    do {
        r = x % d;
        if (r == 0)
            divTot = divTot + d;
        d = d + 1;
    } while (d < x);
    if (x == divTot)
        *ris = true;
    else
        *ris = false;
}
int main() {
    int n;
    bool ris;
    do {
        printf("inserire un numero: \n");
        scanf("%d", &n);
    } while (n < 0);
    ePerf(n, &ris);
    printf("%d", ris);
    return 0;
}
