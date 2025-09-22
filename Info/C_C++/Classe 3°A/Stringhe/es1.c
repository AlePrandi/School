/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define LUNG_MAX 100

int main(){
char s1[]="a";
char s2[]= {'c', 'i', 'a', 'o'};
char s3[]= "";

char s[LUNG_MAX];

printf("lettura con spazi tramite gets, inserisci una frase: ");
fflush(stdin);
gets(s);
printf("hai inserito: %s", s);

return 0;
}
/*
for(int k = 0; s[k] != '\0';k++)
*/
