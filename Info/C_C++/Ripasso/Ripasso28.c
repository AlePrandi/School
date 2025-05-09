#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX 30

typedef struct
{
    char *NomeSquad;
    int golFatti;
    int golSubiti;
} Squadra;

void CaricaCamp(Squadra p[MAX])
{
    for (int k = 0; k < MAX; k++)
    {
        printf("inserisci il nome della squadra: ");
        fflush(stdin);
        gets(p[k].NomeSquad);
        printf("inserisci il numero di gol fatti: ");
        scanf("%d", &p[k].golFatti);
        printf("inserisci il numero di gol subiti: ");
        scanf("%d", &p[k].golSubiti);
    }
}

void StampaCamp(Squadra p[MAX])
{
    for (int k = 0; k < MAX; k++)
    {
        if (p[k].golFatti > p[k].golSubiti)
        {
            printf("%s ha più gol fatti che subiti", p[k].NomeSquad);
        }
    }
}

void CercaSquad(Squadra p[MAX], char squad[MAX])
{
    for (int k = 0; k < MAX; k++)
    {
        if (strcmp(p[k].NomeSquad,squad) == 0)
        {
            printf("La squadra %s ha fatto %d gol e ha subito %d gol", p[k].NomeSquad, p[k].golFatti, p[k].golSubiti);
        }else{
            printf("La squadra cercata non è presente nel campionato");
        }
    }
}

int main()
{
    Squadra campionato[MAX];
    char *squadra;

    CaricaCamp(campionato);
    StampaCamp(campionato);
    printf("inserisci il nome della squadra da cercare: ");
    fflush(stdin);
    gets(squadra);
    CercaSquad(campionato, squadra);

    return 0;
}