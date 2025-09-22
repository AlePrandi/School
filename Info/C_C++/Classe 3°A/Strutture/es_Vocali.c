/*
author: Prandi Alessandro
date:
es.
testo
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LUNG 100

bool rimuoviVocali(char s) {
    bool  contr = true;
    if (s != 'a' && s != 'e' && s != 'i' && s != 'o' && s != 'u' &&
            s != 'A' && s != 'E' && s != 'I' && s != 'O' && s != 'U') {
        contr = false;
    }
    return contr;
}

int main() {

    FILE *fp,*fp1;
    char ch;
    char nomeFile[LUNG];
    printf("inserisci il nome del file: ");
    gets(nomeFile);
    if ((fp = fopen(nomeFile,"r"))!= NULL) {
        if ((fp1 = fopen("temp.txt","w"))!= NULL) {
            while(fscanf(fp,"%c",&ch)!= EOF) {
                if (rimuoviVocali(ch) == false) {
                    fprintf(fp1,"%c",ch);
                }
            }
            fclose(fp1);
            fclose(fp);
            remove(nomeFile);
            rename("temp.txt","dati.dat");
        } else {
            printf("Errore apertura file temporaneo");
            fclose(fp);
        }
    } else

        printf("Errore apertura file da modificare");
    return 0;
}
