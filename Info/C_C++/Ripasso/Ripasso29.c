#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 20
#define NGIORNI 7
#define DIM 100
#define PERC 10

typedef struct
{
    char nome[LUNG];
    float valori[NGIORNI];
} Quotazione;

void CaricaAzioni(Quotazione vett[], int n, int giorni)
{
    for (int k = 0; k < n; k++)
    {
        printf("Inserisci il nome dell'azienda[%d]: ", k + 1);
        fflush(stdin);
        scanf("%s", vett[k].nome);
        for (int i = 0; i < giorni; i++)
        {
            printf("inserire il valore del giorno [%d]: ", i + 1);
            scanf("%f", &vett[k].valori[i]);
        }
    }
}

int caloAzioni(Quotazione vett[], int n, int giorni)
{
    int cont;
    int n_aziende = 0;
    for (int k = 0; k < n; k++)
    {
        cont = 0;
        int i = 1;
        while (i < giorni && cont == 0)
        {
            float q;
            q = vett[k].valori[i - 1] * PERC / 100;
            if (vett[k].valori[i] < vett[k].valori[i - 1] - q)
            {
                cont++;
            }
            i++;
        }
        if (cont != 0)
        {
            n_aziende++;
            printf("l'azienda %s ha avuto cali maggiori del %d\n", vett[k].nome, PERC);
        }
    }
    return n_aziende;
}

int main()
{
    Quotazione vett[DIM];

    CaricaAzioni(vett, DIM, NGIORNI);
    int n_aziende = caloAzioni(vett, DIM, NGIORNI);
    printf("le aziende che hanno avuto un calo maggiore di [%d] sono: %d\n", PERC, n_aziende);
    caloAzioni(vett, DIM, NGIORNI);
    return 0;
}