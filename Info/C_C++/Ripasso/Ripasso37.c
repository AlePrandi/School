#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#define MAX 10

typedef struct
{
    char *nome;
    char *cognome;
    float tempo;
} Concorrente;

void scambio(Concorrente *n1, Concorrente *n2)
{
    Concorrente z;
    z = *n1;
    *n1 = *n2;
    *n2 = z;
}

void caricaFile(Concorrente a[], int dim)
{
    FILE *fp;
    char *nomeFile = "GARE.txt";
    int k = 0;
    fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        printf("Problemi apertura file");
    }
    else
    {
        while (fscanf(fp, "%s %s %f", a[k].nome, a[k].cognome, a[k].tempo) != EOF && k < dim)
        {
            k++;
        }
    }
    fclose(fp);
}

void Classifica(Concorrente a[], int dim)
{
    int sup, sca;
    sup = dim - 1;
    while (sup > 0)
    {
        sca = 0;
        for (int k = 0; k < sup; k++)
        {
            if (a[k].tempo < a[k + 1].tempo)
            {
                scambio(&a[k], &a[k + 1]);
                sca = k;
            }
        }
        sup = sca;
    }
}

int main()
{

    Concorrente gara[MAX];
    caricaFile(gara, MAX);
    Classifica(gara, MAX);
    printf("Il concorrente %s %s ha vinto la gara", gara[0].nome, gara[0].cognome);

    return 0;
}
