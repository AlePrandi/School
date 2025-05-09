/*
author: Prandi Alessandro
date: 25/01/2023
es. 2023
testo
*/

#include <stdio.h>
#include <stdlib.h>
int fib(int n) {
    int ris;
    if ( n == 0 || n == 1) {
        return n;
    } else {
        return fib( n -1) + fib (n - 2);
    }
}
/*
fib(0)= 0;
fib(1)= 1;
fib(n)= fib(n -1) + fib(n -2);
*/
int main() {
    int n;
    printf("inserisci un numero: ");
    scanf("%d", &n);
    printf("il numero in quella posizione e: %d", fib(n));
    return 0;
}
