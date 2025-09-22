#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

void caricaFile()
{
    FILE *fp, *fp2;
    char reparto[MAX], prodotto[MAX];
    float prezzoSing;
    int quanti, PercSconto;
    fp = fopen("AmasonPraim.txt", "r");
    fp2 = fopen("ProdottiScontati.txt", "w");
    if (fp == NULL)
    {
        printf("Problemi apertura file");
    }
    else
    {
        while (fscanf(fp, "%s %s %f %d %d", reparto, prodotto, &prezzoSing, &quanti, &PercSconto) != EOF)
        {
            if (PercSconto > 0)
            {
                fprintf(fp2, "%s %s %f %d %d \n", reparto, prodotto, prezzoSing, quanti, PercSconto);
            }
        }
    }
    fclose(fp);
    fclose(fp2);
}

int main()
{
    caricaFile();
}