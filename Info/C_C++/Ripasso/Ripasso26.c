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

bool Espec(int mat[M][N])
{
    bool Spec = true;
    int r = 0;
    while (r < M && Spec == true)
    {
        int c = 0;
        while (c < N/2 && Spec == true)
        {
            if (mat[r][c] != mat[r][N - 1 - c])
            {
                Spec = false;
            }
            c++;
        }
        r++;
    }
    return Spec;
}

int main()
{
    int matrice[M][N];

    CaricaMat(matrice);

    if (Espec(matrice))
    {
        printf("La matrice e' speculare\n");
    }
    else
    {
        printf("La matrice non e' speculare\n");
    }

    return 0;
}