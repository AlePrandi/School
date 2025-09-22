#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 10000

typedef struct{
    char reparto[MAX];
    char prodotto[MAX];
    float prezzoSing;
    int quanti;
    int PercSconto;
} Prod;

typedef struct{
    char reparto[MAX];
    int numeroProd;
    float EuroSconto;
    float EuroTot;
}Rep;

void caricaFile()
{
    FILE *fp, *fp2;
    Prod Lista[MAX];
    Rep Cat[MAX];
    float ScontoEuro;
    int cont = 0;
    int Ncat = 0;
    fp = fopen("AmasonPraim.txt", "r");
    if (fp == NULL)
    {
        printf("Problemi apertura file");
    }
    else
    {
        while (fscanf(fp, "%s %s %f %d %d", Lista[cont].reparto, Lista[cont].prodotto, &Lista[cont].prezzoSing, &Lista[cont].quanti, &Lista[cont].PercSconto) != EOF)
        {
            if(strcmp(Lista[cont].reparto,"TV") == 0){
                strcpy(Cat[Ncat].reparto, "TV");
                Cat[Ncat].numeroProd += Lista[cont].quanti;
                Cat[Ncat].EuroTot += Lista[cont].prezzoSing * Lista[cont].quanti;
                ScontoEuro = Lista[cont].prezzoSing * Lista[cont].PercSconto / 100;
                Cat[Ncat].EuroSconto += ScontoEuro * Lista[cont].quanti;
            }else{
                if(strcmp(Lista[cont].reparto,"Computer") == 0){
                Ncat = 1;
                strcpy(Cat[Ncat].reparto, "Computer");
                Cat[Ncat].numeroProd += Lista[cont].quanti;
                Cat[Ncat].EuroTot += Lista[cont].prezzoSing * Lista[cont].quanti;
                ScontoEuro = Lista[cont].prezzoSing * Lista[cont].PercSconto / 100;
                Cat[Ncat].EuroSconto += ScontoEuro * Lista[cont].quanti;
            }else{
                if(strcmp(Lista[cont].reparto,"Cat[Ncat]") == 0){
                Ncat = 2;
                strcpy(Cat[Ncat].reparto, "Cat[Ncat]");
                Cat[Ncat].numeroProd += Lista[cont].quanti;
                Cat[Ncat].EuroTot += Lista[cont].prezzoSing * Lista[cont].quanti;
                ScontoEuro = Lista[cont].prezzoSing * Lista[cont].PercSconto / 100;
                Cat[Ncat].EuroSconto += ScontoEuro * Lista[cont].quanti;
            }
            }
            }
            cont++;
        }
    }
    for (int i = 0; i < Ncat; i++){
        printf("REAPRTO: %s \n", Cat[i].reparto);
        printf("Il numero dei prodotti scontati e: %d\n", Cat[i].numeroProd);
        printf("il totale in euro dello sconto applicato è %.2f euro su un totale di %.2f euro", Cat[i].EuroSconto, Cat[i].EuroTot);
    }
    fclose(fp);
}

int main()
{
    caricaFile();
}