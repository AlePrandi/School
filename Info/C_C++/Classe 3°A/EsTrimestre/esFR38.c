/*
author: Prandi Alessandro
date: 26/01/2023
es. FR38
testo
*/

#include <stdio.h>
#include <stdlib.h>

void f(int x) {
    if (x == 0) {
        printf("%d\n", x);
    } else {
        printf("%d\n", x);
        f(x -1);
    }
}

void freverse(int x){
if (x == 0){
        printf("%d\n", x);
    } else {
        freverse(x -1);
        printf("%d\n", x);
    }
}
int main() {
    int n;
    do {
        printf("inserisci il numero di partenza: ");
        scanf("%d", &n);
    } while(n < 0);
    f(n);
    freverse(n);
    return 0;


}
