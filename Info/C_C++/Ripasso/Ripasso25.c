/*
author: Alessandro Prandi
date:
es.
testo:
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define M 4
#define N 4

void CaricaMat(int matrice[][N])
{
    for (int righe = 0; righe < M; righe++)
    {
        for (int colonne = 0; colonne < N; colonne++)
        {
            printf("Inserisci un numero[%d][%d]:", righe, colonne);
            scanf("%d", &matrice[righe][colonne]);
        }
    }
}

bool Esimmetrico(int mat[M][N])
{
    bool Sim = true;
    if (M != N)
    {
        Sim = false;
    }

    for (int i = 0; i < M; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (mat[i][j] != mat[j][i])
            {
                Sim = false;
            }
        }
    }

    return Sim;
}

int main()
{
    int matrice[M][N];

    CaricaMat(matrice);

    if (Esimmetrico(matrice))
    {
        printf("La matrice e' simmetrica\n");
    }
    else
    {
        printf("La matrice non e' simmetrica\n");
    }

    return 0;
}