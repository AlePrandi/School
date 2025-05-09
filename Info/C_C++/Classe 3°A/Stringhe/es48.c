/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG_MAX 100

int main(){
    char s[LUNG_MAX];
    char srad[LUNG_MAX];
    int lunghezza;
    printf("\nInserire una stringa: ");
    fflush(stdin);
    gets(s);
    lunghezza=strlen(s);
    int k=0;
    int j=0;
    while(s[j]!= '\0'){
    if(s[j]=='a' || s[j]=='e' || s[j]=='i' || s[j]=='o' || s[j]=='u'){
        srad[k++]=s[j];
    }
    srad[k++]=s[j++];
    }
    srad[k]='\0';
    printf("Stringa raddoppiata: %s",srad);
}
