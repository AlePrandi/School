/*
autor: Prandi Alessandro
es. 3
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define GIORNO_ATT 31
#define MESE_ATT 05
#define ANNO_ATT 2023
#define LUNG 20

typedef struct
{
    int giorno;
    int mese;
    int anno;
} Data;

typedef struct
{
    char Nome[LUNG];
    Data nascita;
    int altezza;
} Persona;

void caricaDati(Persona p)
{
    printf("inserisci il nome della persona: ");
    fflush(stdin);
    gets(p.Nome);
    printf("inserisci la data di nascita della persona(xx/xx/xxxx): ");
    scanf("%d/%d/%d", &p.nascita.giorno, &p.nascita.mese, &p.nascita.anno);
    printf("inserisci l'altezza della persona in cm: ");
    scanf("%d", &p.altezza);
}

bool eMaggiorenne(Persona p, int giorno, int mese, int anno)
{
    bool  magg = true;
    if (anno - p.nascita.anno < 0)
    {
        magg = false;
    }
    else if(anno - p.nascita.anno == 0)
    {
        if (mese - p.nascita.mese < 0)
        {
            magg = false;
        }
        else if(mese - p.nascita.mese == 0)
        {
            if (giorno - p.nascita.giorno < 0)
            {
                magg = false;
            }
            if(giorno - p.nascita.giorno == 0)
            {
                magg = true;
            }
        }
    }
}

int main()
{
    Persona p;
    caricaDati(p);
    if(eMaggiorenne(p,GIORNO_ATT,MESE_ATT,ANNO_ATT) == true)
    {
        printf("%s e' maggiorenne", p.Nome);
    }
    else
        printf("%s e'minorenne", p.Nome);

    return 0;
}
