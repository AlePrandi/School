/*
author: Prandi Alessandro
date: 9/11/22
es.041
testo
*/

#include <stdio.h>
#include <stdlib.h>

 main()
{
    float a,b,c,x;// tre numeri e variabile di lavoro

    printf("insersici il numero A:");//funzione input
    scanf("%f", &a);
    printf("insersici il numero B:");
    scanf("%f", &b);
    printf("insersci il numero C:");
    scanf("%f", &c);
    if (a < b){
        x = a;
        a = b;
        b = x;
    }

    if (a <c ){
        x = a;
        a = c;
        c = x;
    }

    if (b < c){
        x = b;
        b = c;
        c = x;
    }

    printf("A: %.2f,B: %.2f,C: %.2f",a,b,c);//funzione output
}
