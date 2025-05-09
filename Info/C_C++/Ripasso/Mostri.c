#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define FORZA_MAX 10
#define FORZA_MIN 5
#define MAX_MOSTRI 10
#define VITA_MAX 100
#define VITA_MIN 0
#define VITA_MIN_RAND 30
#define DADO_MAX 6
#define DADO_MIN 1

typedef struct
{
    char *nome;
    int forza;
    int vita;
} Mostro;

void setVita(Mostro *m, int vita)
{
    m->vita = vita;
}

void setForza(Mostro *m, int forza)
{
    m->forza = forza;
}

int getForza(Mostro m)
{
    return m.forza;
}

int getVita(Mostro m)
{
    return m.vita;
}

int getLancio(Mostro m)
{
    int punteggio;
    punteggio = m.forza * (DADO_MIN + rand() % (DADO_MAX + 1 - DADO_MIN));
    return punteggio;
}

void creaMostro(Mostro m, char nome[], int vita, int forza)
{
    m.nome = nome;
    setForza(&m, forza);
    setVita(&m, vita);
}

void creaMostroRand(Mostro m, char nome[])
{
    int RandForza, RandVita;
    m.nome = nome;
    RandForza = FORZA_MIN + rand() % (FORZA_MAX + 1 - FORZA_MIN);
    RandVita = VITA_MAX + rand() % (VITA_MAX + 1 - VITA_MIN);
    setForza(&m, RandForza);
    setVita(&m, RandVita);
}

void combattimento(Mostro m1, Mostro m2)
{
    int lancio1, lancio2;
    lancio1 = getLancio(m1);
    lancio2 = getLancio(m2);
    if (lancio1 > lancio2)
    {
        setVita(&m2, m2.vita - lancio1);
    }
    else
    {
        setVita(&m1, m1.vita - lancio2);
    }
}

int menu()
{
    int scelta;

    printf("0- esci \n");
    printf("1- crea mostro \n");
    printf("2- gioca \n");
    printf("3- stampa mazzo \n");
    printf("scelta: ");
    scanf("%d", &scelta);

    return scelta;
}

int main()
{
    int contAll = 0, contAvv = 0;
    int scelta;
    int sel, random; // scelta tra creazione mostro random o normale
    char *Allnome;
    int AllVita, AllForza;
    char *Avvnome;
    int AvvVita, AvvForza;
    int numAll, numAvv; // contatori scelta mostro con cui giocare
    int mazzo;
    Mostro mostroAll[MAX_MOSTRI];
    Mostro mostroAvv[MAX_MOSTRI];

    srand(time(NULL));

    do
    {
         scelta = menu();
        switch (scelta)
        {
        case 0:
            break;
        case 1:
            printf("Vuoi creare un mostro alleato(1) o nemico(2): ");
            scanf("%d", &sel);
            if (sel == 1)
            {
                printf("Vuoi crearlo randomizzato(1) o no(2): ");
                scanf("%d", &random);
                if (random == 1)
                {
                    printf("Inserisci il nome del mostro: ");
                    fflush(stdin);
                    scanf("%s", Allnome);
                    creaMostroRand(mostroAll[contAll], Allnome);
                    contAll++;
                }
                else
                {
                    printf("Inserisci il nome del mostro: ");
                    fflush(stdin);
                    scanf("%s", Allnome);
                    do
                    {
                        printf("inserisci la vita del mostro(0...100): ");
                        scanf("%d", &AllVita);
                    } while (AllVita < VITA_MIN || AllVita > VITA_MAX);
                    do
                    {
                        printf("inserisci la forza del mostro(5...10): ");
                        scanf("%d", &AllForza);
                    } while (AllForza < FORZA_MIN || AllForza > FORZA_MAX);
                    creaMostro(mostroAll[contAll], Allnome, AllVita, AllForza);
                    contAll++;
                }
            }
            else
            {
                printf("Vuoi crearlo randomizzato(1) o no(2): ");
                scanf("%d", &random);
                if (random == 1)
                {
                    printf("Inserisci il nome del mostro: ");
                    fflush(stdin);
                    scanf("%s", Avvnome);
                    creaMostroRand(mostroAvv[contAvv], Avvnome);
                    contAvv++;
                }
                else
                {
                    printf("Inserisci il nome del mostro: ");
                    fflush(stdin);
                    scanf("%s", Avvnome);
                    do
                    {
                        printf("inserisci la vita del mostro(0...100): ");
                        scanf("%d", &AvvVita);
                    } while (AvvVita < VITA_MIN || AvvVita > VITA_MAX);
                    do
                    {
                        printf("inserisci la forza del mostro(5...10): ");
                        scanf("%d", &AvvForza);
                    } while (AvvForza < FORZA_MIN || AvvForza > FORZA_MAX);
                    creaMostro(mostroAvv[contAvv], Avvnome, AvvVita, AvvForza);
                    contAvv++;
                }
            }
        break;
        case 2:
            do
            {
                printf("con quale mostro alleato vuoi combattere: ");
                scanf("%d", &numAll);
            } while (numAll > contAll || numAll < 0);
            do
            {
                printf("con quale mostro avversario vuoi combattere: ");
                scanf("%d", &numAvv);
            } while (numAvv > contAvv || numAvv < 0);
            combattimento(mostroAll[numAll], mostroAvv[numAvv]);
        break;
        case 3:
            printf("stampare il mazzo alleato(1) o avversario(2): ");
            scanf("%d", &mazzo);
            if (mazzo == 1)
            {
                for (int k = 0; k < contAll; k++)
                {
                    printf("Mostro %d: \n", k);
                    printf("nome: %s  forza: %d  vita: %d \n", mostroAll[k].nome, mostroAll[k].forza, mostroAll[k].vita);
                }
            }
            else
            {
                for (int k = 0; k < contAvv; k++)
                {
                    printf("Mostro %d: \n", k);
                    printf("nome: %s  forza: %d  vita: %d \n", mostroAvv[k].nome, mostroAvv[k].forza, mostroAvv[k].vita);
                }
            }
        break;
        default:
        break;
        }
    } while(scelta != 0);
    return 0;
}