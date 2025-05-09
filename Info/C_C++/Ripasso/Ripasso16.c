/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#define LUNG 100
#define MAX 122
#define MIN 65

void CreaStringa(char str[LUNG], int num){
    for(int k = 0; k < num; k++){
        str[k] = MIN + rand() % (MAX + 1 - MIN);
    }
}

int main(){
    int n;
    srand(time(NULL));
    do{
    printf("inserisci lunghezza della stringa: ");
    scanf("%d", &n);
    } while(n < 1);
    char stringa[n + 1];
    CreaStringa(stringa, n + 1);
    puts(stringa);

return 0;
}
