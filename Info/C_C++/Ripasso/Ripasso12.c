/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define MAX 11

void tabellina(int num, int vett[MAX]){
for(int k = 0; k < MAX;k ++){
    vett[k] = num * k;
}
}

int main(){
int vett[MAX], numero;

printf("inserire un numero: ");
scanf("%d", &numero);
tabellina(numero, vett);
printf("la tebellina di %d e': \n", numero);
for(int j = 0; j < MAX; j++){
    printf("%d ",vett[j]);
}
return 0;
}
