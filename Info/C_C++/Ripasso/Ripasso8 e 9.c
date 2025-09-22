/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float potenza(float x){
x = x * x;
return x;
}

float ipotenusa(float cateto1, float cateto2){
 float ris;
 ris = sqrt(potenza(cateto1) + potenza(cateto2));
 return ris;
}

int main(){
    float cat1,cat2,ipo;
    printf("inserisci il primo cateto: ");
    scanf("%f", &cat1);
    printf("inserisci il secondo cateto: ");
    scanf("%f", &cat2);
    ipo = ipotenusa(cat1, cat2);
    printf("l'ipotenusa e': %.2f", ipo);
return 0;
}
