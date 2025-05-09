#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 21
#define PROVE 10

typedef struct
{
    char nome[MAX];
    int val_giorno[PROVE];
    int totale;
} Atleta;

int chiediDim(int n_max, char *stringa)
{
    int x;
    do
    {
        printf("%s ", stringa);
        scanf("%d", &x);
    } while (x < 0 || x > n_max);
    return x;
}

void CaricaAtleta(Atleta s[], int n, int prove)
{
    
    for (int k = 0; k < n; k++)
    {
        s[k].totale = 0;
        printf("Inserisci il nome dell'atleta[%d]: ", k + 1);
        fflush(stdin);
        scanf("%s", s[k].nome);
        for (int i = 0; i < prove; i++)
        {
            printf("inserire il punteggio della prova [%d]: ", i + 1);
            scanf("%d", &s[k].val_giorno[i]);
            s[k].totale += s[k].val_giorno[i];
        }
    }
}

void scambio(Atleta *n1, Atleta *n2)
{
    Atleta z;
    z = *n1;
    *n1 = *n2;
    *n2 = z;
}

void Decrescenti(Atleta s[], int n)
{
    int sup, sca;
    sup = n - 1;
    while (sup > 0)
    {
        sca = 0;
        for (int k = 0; k < sup; k++)
        {
            if (s[k].totale < s[k + 1].totale)
            {
                scambio(&s[k], &s[k + 1]);
                sca = k;
            }
        }
        sup = sca;
    }
}

void Classifica(Atleta s[], int n, int prove)
{
    Decrescenti(s, n);
    printf("Il vincitore e': %s con %d punti\n", s[0].nome, s[0].totale);
    for (int k = 1; k <= n - 1; k++)
    {
        printf("Il concorrente %s si e' posizionato %d con %d punti\n", s[k].nome, k + 1, s[k].totale);
    }
}

int main()
{
    char *frase = "inserisci il numero di giocatori:";
    int dim = chiediDim(MAX, frase);
    Atleta n_giocatori[dim];
    CaricaAtleta(n_giocatori, dim, PROVE);
    Classifica(n_giocatori, dim, PROVE);
}