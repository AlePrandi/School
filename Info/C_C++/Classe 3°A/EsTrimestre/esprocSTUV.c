/*
author: Prandi Alessandro
date: 20/12/2022
es. S T U V
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
float quoto( float num1, float num2){
float div;
if (num1 < 0)
    div = 0;
else
    if (num2 < 0)
        div = 0;
    else
        div = num1 / num2;
return div;
}
bool eBello(int base, int altezza){
    bool bello;
    int divis;
    divis = quoto(base, altezza);
    if (divis == 3)
        bello = true;
    else
        bello = false;
return bello;
}
void nrett(int n){
    int k;
    float b,a;
for(k = 0; k < n; k++){
    printf("inserisci la base: ");
    scanf("%f", &b);
    printf("inserisci l'altezza: ");
    scanf("%f", &a);
    if (eBello(b, a) == true)
        printf("e un rettangolo bello\n");
    else
        printf("non e un rettangolo bello\n");
}
}
int main(){
    int nvolte;
    printf("inserisci il numero di rettangoli di cui vuoi sapere se sono belli: \n");
    scanf("%d", &nvolte);
    nrett(nvolte);
return 0;
}
