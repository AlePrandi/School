/*
author: Prandi Alessandro
date:14/11/2022
es.55
testo
*/

#include <stdio.h>
#include <stdlib.h>

main(){
 int n,d;

printf("inserisci un numero: ");
scanf("%d", &n);
while(n!=0)
{
    d = n * 2;
    printf("il doppio e: %d \n", d);
    printf("inserisci un numero: ");
    scanf("%d", &n);
 }
 printf("nessun numero");
}
