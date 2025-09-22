/*
author: Prandi Alessandro
date: 24/01/2023
es. 134
testo
*/

#include <stdio.h>
#include <stdlib.h>
void calcolo(float n1, char op, float n2){
    float ris;
switch(op){

case '+':
    ris = n1 + n2;
    break;
case '-':
    ris = n1 - n2;
    break;
case '*':
    ris = n1 * n2;
    break;
case '/':
    ris = n1 / n2;
    break;
}
printf("il risultato e: %.2f", ris);
}

main(){
    float n1,n2;
    char op;
 printf("inserisci un espressione: ");
 scanf("%f %c %f", &n1, &op, &n2);
calcolo(n1,op,n2);
}
