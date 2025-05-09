/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fp;
    FILE *fp1;
    float num;
    float somma;
    float ris;
    float cont = 0;
    float max;
    fp = fopen("numeri.dat", "r");
    fp1 = fopen("risultati.dat", "w");
    if (fp == NULL || fp1 == NULL)
    {
        printf("problemi con i file\n");
    }
    else
    {
        while (fscanf(fp, "%f", &num) != EOF)
        {
            if (cont == 0)
            {
                max = num;
            }
            else
            {
                if (num > max)
                {
                    max = num;
                }
            }
            cont++;
            somma += num;
        }
        
        if (somma == 0)
        {
            printf("Il file era vuoto!\n");
        }
        else
        {
            ris = somma / cont;
            fprintf(fp1, "Media: %.2f\n", ris);
            fprintf(fp1, "Max: %.2f\n", max);
        }
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}