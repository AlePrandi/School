#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

void caricaFile()
{
    FILE *fp;
    char reparto[MAX], prodotto[MAX];
    float prezzoSing, ScontoEuro;
    int quanti, PercSconto;
    float MaxSconto;
    char MaxNome[MAX];
    char nomeFile[MAX] = "AmasonPraim.txt";
    int cont = 0;
    fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        printf("Problemi apertura file");
    }
    else
    {
        while (fscanf(fp, "%s %s %f %d %d", reparto, prodotto, &prezzoSing, &quanti, &PercSconto) != EOF)
        {
            ScontoEuro = prezzoSing * PercSconto / 100;

            if (cont == 0)
            {
                strcpy(MaxNome, prodotto);
                MaxSconto = ScontoEuro;
            }
            else
            {
                if (MaxSconto < ScontoEuro)
                {
                    MaxSconto = ScontoEuro;
                    strcpy(MaxNome, prodotto);
                }
            }
            cont++;
        }
    }
    printf("AMASONPRAIM \n");
    printf("AMASON CONSIGLIA: \n");
    printf("- prodotto %s ", MaxNome);
    printf("solo per oggi e domani scontato di %.2f euro", MaxSconto);
    fclose(fp);
}

int main()
{
    caricaFile();
}