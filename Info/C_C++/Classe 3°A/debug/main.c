#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define DIM 5
#define MIN 0
#define MAX 100

void carica(int v[], int n){
srand(time(NULL));
for(int k = 0; k < n;k++){
    v[k]= MIN + rand() % (MAX + 1 - MIN);
}
}

int main()
{
    int a, b, ris;
    int vettA[DIM];
    a = 10;
    b = 5;
    ris= somma(a, b);
    carica(vettA, DIM);


    return 0;
}
