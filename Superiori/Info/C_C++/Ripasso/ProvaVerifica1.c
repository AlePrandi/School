#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

void caricaFile()
{
    FILE *fp;
    char data[MAX], insegnante[MAX], materia[MAX], cognome[MAX];
    float voto,somma, media;
    char nomeFile[MAX] = "DatiVerifica.txt";
    int cont = 0;

    fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        printf("Problemi apertura file");
    }
    else
    {
        while (fscanf(fp, "%s %s %s %s %f", data, insegnante, materia,cognome, &voto) != EOF)
        {
            somma += voto;
            cont++;
        }
    }
    media = somma / cont;
    printf("I voti sono %d e la media %.2f \n", cont, media);
    fclose(fp);
}

int main(){
    caricaFile();
}