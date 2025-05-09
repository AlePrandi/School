/*
author: Prandi Alessandro
date:9/11/2022
es.25
testo
*/

#include <stdio.h>
#include <stdib.h>

main(){
 float num;

 printf("insersci un nmero: ");
 scanf("%f",num);

 if(num>0)
    printf("il numero e positivo");
 else
    if(num==0)
        printf("il numero e nullo");
    else
        printf("il numero e negativo");

}
