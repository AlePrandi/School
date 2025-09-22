/*
author: Prandi Alessandro
date: 20/12/2022
es. N
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float valip(float l1, float l2){
float ip;
ip = sqrt((l1 * l1) + (l2 * l2));
return ip;
}
float perim(float l1, float l2, float ip){
    float per;
    per = l1 + l2 + ip;
    return per;
}
float area(float l1, float l2){
    float ar;
    ar = (l1 * l2) / 2;
    return ar;
}

void calcola(float valip, float perim, float area){
printf("l'ipotenusa e: %.2f", valip);
printf("il perimetro e: %.2f", perim);
printf("l'area e: %.2f", area);
}
int main(){
float l1, l2, ipot, per, ar;
printf("inserisci la base: ");
scanf("%f", &l1);
printf("inserisci l'altezza: ");
scanf("%f", &l2);
ipot = valip(l1,l2);
per = perim(l1, l2 , ipot);
ar = area( l1, l2);
calcola(ipot, per, ar);
return 0;
}
