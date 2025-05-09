#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

typedef struct{
    char nome[MAX];
    float media;
}Studente;

void caricaMediaMia()
{
    Studente alunno;
    FILE *fp,*fp1;
    fp1 = fopen("Prandi.txt", "a");
    printf("Inserisci il nome dell'alunno: ");
    fflush(stdin);
    scanf("%s", alunno.nome);
    char data[MAX], insegnante[MAX], materia[MAX], cognome[MAX];
    float voto,somma, media;
    char nomeFile[MAX] = "DatiVerifica.txt";
    int cont = 0;

    fp = fopen(nomeFile, "r");
    if (fp == NULL)
    {
        printf("Problemi apertura file");
    }else if(fp1 == NULL){
        fp1 = fopen("Prandi.txt", "w");
    }
    else
    {
        while (fscanf(fp, "%s %s %s %s %f", data, insegnante, materia,cognome, &voto) != EOF)
        {
            for (int k = 0; k < cont; k++){
            if(strcmp(cognome,alunno.nome) == 0){
            somma += voto;
            cont++;               
            }                
            }
        }
    }
    media = somma / cont;
    printf("La media dei voti dell'alunno %s e' %.2f \n", alunno.nome, media);
    fprintf(fp1,"Media: %f", media);
    fclose(fp);
}

int main(){
    caricaMediaMia();
}