/*
author: Prandi Alessandro
date:10/11/2022
es.1 verifica
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define CAP 20
main(){

 int x,r,npul;

 do{
 printf("inserire il numero il numero di studenti: ");
 scanf("%d", &x);
 }
 while (x < 0);
 npul = x / CAP;
 r = x % CAP;
 if (r != 0)
    npul++;
 printf("il numero di pullman e %d", npul);
}
