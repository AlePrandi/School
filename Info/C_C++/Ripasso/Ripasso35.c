/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define LUNG_FRASE 20
#define LUNG_TESTO 100

bool isLettera(char c){
    bool eLett = true;
    if ( c == ' ' || c == ',' || c == '.'){
        eLett = false;
    }
    return eLett;
}

int main()
{
    FILE *fp;
    char testo[LUNG_FRASE][LUNG_TESTO];
    int lettere = 0;
    int frasi = 0;

    fp = fopen("testo.txt", "r");
    if (fp == NULL)
    {
        printf("problemi con i file\n");
    }
    else
    {
        while (fscanf(fp, "%c", testo[lettere][frasi]) != EOF)
        {
            if(isLettera(testo[lettere][frasi] == false)){
                lettere--;
                frasi++;
            }
            lettere++;
            printf("%c", testo[lettere][frasi]);
        }
        printf("\n");
        printf("le lettere nel testo sono: %d\n", lettere);
        printf("le fresi nel testo sono: %d\n", frasi);
    }
    fclose(fp);
    return 0;
}