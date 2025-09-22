/*
author: Prandi Alessandro
date: 25/01/2023
es. fatt
testo
calcolo del fattoriale in modo ricorsivo
*/

#include <stdio.h>
#include <stdlib.h>
fatt(int n){
int ris;
if (n == 0)
    ris = 1;
else
    ris = n * fatt(n -1);
return ris;
}

void ast(int n){
if (n == 1)
    printf("*");
else
{
    printf("*");
    ast(n -1);
}
}

int main(){
    int num,fattoriale;
    printf("inserisci un numero: ");
    scanf("%d", &num);
    fattoriale = fatt(num);
    printf("il fattoriale e %d\n", fattoriale);
    ast(num);
return 0;
}
