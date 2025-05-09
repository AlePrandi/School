/*
author: Prandi Alessandro
date: 18/12/2022
es. M
testo
*/

#include <stdio.h>
#include <stdlib.h>
void aQuad(float lato){
float area;
area = lato * lato;
printf("l'area e: %.2f", area);
}
void pQuad(float lato){
float perimetro;
perimetro = lato * 4;
printf("il perimetro e: %.2f", perimetro);
}

int main(){
    float lato;
    printf("inserisci un lato: ");
    scanf("%f", &lato);
    aQuad(lato);
    printf("\n");
    pQuad(lato);

return 0;
}
