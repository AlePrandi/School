/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>

int inverti(int num){
    int p1,p2,ris;
    p1 = num % 10;
    p2 = (num -p1) / 10;
    ris = p1* 10 + p2;
return ris;
}

int main(){
    int num;
    printf("inserisci un numero: ");
    scanf("%d", &num);
    num = inverti(num);
    printf("numero invertito: %d", num);
return 0;
}
