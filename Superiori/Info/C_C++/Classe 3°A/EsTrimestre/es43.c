/*
author: Prandi Alessandro
date: 14/11/2022
es.43
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define SC1 15
#define SC2 10
#define E1 60
#define E2 12
main(){
 int eta;
 float cb,pr;
 printf("inserisci l'eta: ");
 scanf("%d", &eta);
 printf("inserisci il costo del biglietto: ");
 scanf("%f", &cb);
 if(eta > E1 || eta <= E2){
    if(eta > E1)
        pr = cb - (cb * SC1 / 100);
    else
        pr = cb - (cb * SC2 / 100);
 }
 else
    pr = cb;
printf("il prezzo e %f", pr);
}
