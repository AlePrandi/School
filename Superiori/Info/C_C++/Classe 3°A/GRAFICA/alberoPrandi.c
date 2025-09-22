/*
author: Prandi Alessandro
date: 05/01/2023
es. albero
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include "GraficaPrandi.h"
#include <time.h>
#define LARG 150
#define ALTEZZA 40
// x = colonna
// y = riga

void pupazzo()
{
    rettangoloPienoColore(40, 29, 9, 5, ' ', 255);
    rettangoloPienoColore(41, 25, 7, 4, ' ', 255);
    rettangoloPienoColore(42, 22, 5, 3, ' ', 255);
    rigaColore(42, 23, 1, '*', 240);
    rigaColore(46, 23, 1, '*', 240);
    rigaColore(43, 23, 1, '_', 240);
    rigaColore(44, 23, 1, '_', 240);
    rigaColore(45, 23, 1, '_', 240);
    rigaColore(42, 24, 5, ' ', 68);
    rigaColore(41, 25, 1, ' ', 68);
    rigaColore(40, 26, 1, ' ', 68);
    rigaColore(44, 26, 1, '*', 240);
    rigaColore(44, 28, 1, '*', 240);
    rigaColore(44, 30, 1, '*', 240);
    rigaColore(44, 32, 1, '*', 240);
    rigaColore(40, 21, 9, '-', 96);
    rigaColore(42, 20, 5, '-', 96);

    rettangoloPienoColore(100, 29, 9, 5, ' ', 255);
    rettangoloPienoColore(101, 25, 7, 4, ' ', 255);
    rettangoloPienoColore(102, 22, 5, 3, ' ', 255);
    rigaColore(102, 23, 1, '*', 240);
    rigaColore(106, 23, 1, '*', 240);
    rigaColore(103, 23, 1, '_', 240);
    rigaColore(104, 23, 1, '_', 240);
    rigaColore(105, 23, 1, '_', 240);
    rigaColore(102, 24, 5, ' ', 68);
    rigaColore(101, 25, 1, ' ', 68);
    rigaColore(100, 26, 1, ' ', 68);
    rigaColore(104, 26, 1, '*', 240);
    rigaColore(104, 28, 1, '*', 240);
    rigaColore(104, 30, 1, '*', 240);
    rigaColore(104, 32, 1, '*', 240);
    rigaColore(100, 21, 9, '-', 96);
    rigaColore(102, 20, 5, '-', 96);
}

void neve()
{
    int k, alt;
    alt = 0;
    for (k = 0; k < 34; k++)
    {
        for (int j = 0; j < 10; j++)
        {
            rigaColore(nrandom(1, 149), alt, 1, '*', 31);
        }
        delay(200);
        alt = alt + 1;
    }
}

void pino(float altezza_pino)
{
    int altbase = altezza_pino / 3;
    int dist = 9;
    float altchioma = 40 - 6 - altbase;
    int dist1 = 8;
    float altchioma1 = 40 - 6 - altbase;
    int dist2 = 4;
    float altchioma2 = 40 - 6 - altbase;
    int dist3 = 0;
    float altchioma3 = 40 - 6 - altbase;
    int dist4 = -4;
    float altchioma4 = 40 - 6 - altbase;
    int dist5 = -8;
    float altchioma5 = 40 - 6 - altbase;
    int lungchioma = 19;
    rettangoloPienoColore(LARG / 2 - 1, ALTEZZA - 6 - altbase, 3, altbase, ' ', 102);
    for (int c = 0; c < altezza_pino; c++)
    {
        rigaColore(LARG / 2 - dist, altchioma, lungchioma, ' ', 34);
        dist = dist - 1;
        altchioma = altchioma - 1;
        lungchioma = lungchioma - 2;
    }
    while (1)
    {
        int altbase = altezza_pino / 3;
        int dist = 9;
        float altchioma = 40 - 6 - altbase;
        int dist1 = 8;
        float altchioma1 = 40 - 6 - altbase;
        int dist2 = 4;
        float altchioma2 = 40 - 6 - altbase;
        int dist3 = 0;
        float altchioma3 = 40 - 6 - altbase;
        int dist4 = -4;
        float altchioma4 = 40 - 6 - altbase;
        int dist5 = -8;
        float altchioma5 = 40 - 6 - altbase;
        int lungchioma = 19;
        for (int a = 0; a < 6; a++)
        {
            delay(200);
            rigaColore(LARG / 2 - dist1, altchioma1, 1, ' ', nrandom(15, 255));
            dist1 = dist1 - 2;
            altchioma1 = altchioma1 - 1;
        }
        for (int a = 0; a < 5; a++)
        {
            delay(200);
            rigaColore(LARG / 2 - dist2, altchioma2, 1, ' ', nrandom(15, 255));
            dist2 = dist2 - 2;
            altchioma2 = altchioma2 - 1;
        }
        for (int a = 0; a < 3; a++)
        {
            delay(200);
            rigaColore(LARG / 2 - dist3, altchioma3, 1, ' ', nrandom(15, 255));
            dist3 = dist3 - 2;
            altchioma3 = altchioma3 - 1;
        }
        for (int a = 0; a < 2; a++)
        {
            delay(200);
            rigaColore(LARG / 2 - dist4, altchioma4, 1, ' ', nrandom(15, 255));
            dist4 = dist4 - 2;
            altchioma4 = altchioma4 - 1;
        }
        for (int a = 0; a < 1; a++)
        {
            delay(200);
            rigaColore(LARG / 2 - dist5, altchioma5, 1, ' ', nrandom(15, 255));
            dist5 = dist5 - 2;
            altchioma5 = altchioma5 - 1;
        }
    }
}

void terreno()
{
    int terreno;
    terreno = 39;
    for (int t = 0; t < 6; t++)
    {
        rigaColore(0, terreno, 150, '*', 34);
        terreno = terreno - 1;
    }
}

void regali()
{
    rettangoloPienoColore(86, 31, 5, 3, ' ', 255);
    rigaColore(86, 32, 5, ' ', 68);
    rigaColore(88, 31, 1, ' ', 68);
    rigaColore(88, 33, 1, ' ', 68);
    rettangoloPienoColore(93, 31, 5, 3, ' ', 102);
    rigaColore(93, 32, 5, ' ', 68);
    rigaColore(95, 31, 1, ' ', 68);
    rigaColore(95, 33, 1, ' ', 68);

    rettangoloPienoColore(53, 31, 5, 3, ' ', 85);
    rigaColore(53, 32, 5, ' ', 68);
    rigaColore(55, 31, 1, ' ', 68);
    rigaColore(55, 33, 1, ' ', 68);
    rettangoloPienoColore(60, 31, 5, 3, ' ', 187);
    rigaColore(60, 32, 5, ' ', 68);
    rigaColore(62, 31, 1, ' ', 68);
    rigaColore(62, 33, 1, ' ', 68);
}

int nrandom(int MIN, int MAX)
{
    int nrand;
    nrand = MIN + rand() % (MAX + 1 - MIN);
    return nrand;
}

int main()
{
    float alt;
    do
    {
        printf("inserisci altezza pino: ");
        scanf("%f", &alt);
    } while (alt < 5 || alt > 20);
    setConsoleDimensions(LARG, ALTEZZA);
    rettangoloPienoColore(0, 0, 150, 34, ' ', 17);
    cursor_hide();
    setTextColor(17);
    terreno();
    neve();
    regali();
    pupazzo();
    pino(alt);
    return 0;
}
