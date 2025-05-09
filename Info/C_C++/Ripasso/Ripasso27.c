/*
author: Alessandro Prandi
date:
es.
testo:
*/
#include <stdio.h>
#include <stdlib.h>
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

int Minimo(int mat[M][N])
{
    int minimo = mat[0][0];

    for (int righe = 0; righe < M; righe++)
    {
        for (int colonne = 0; colonne < N; colonne++)
        {
            if (mat[righe][colonne] < minimo)
            {
                minimo = mat[righe][colonne];
            }
        }
    }

    return minimo;
}

int Massimo(int mat[M][N])
{
    int massimo = mat[0][0];

    for (int righe = 0; righe < M; righe++)
    {
        for (int colonne = 0; colonne < N; colonne++)
        {
            if (mat[righe][colonne] > massimo)
            {
                massimo = mat[righe][colonne];
            }
        }
    }

    return massimo;
}

float Media(int mat[M][N])
{
    float somma = 0;

    for (int righe = 0; righe < M; righe++)
    {
        for (int colonne = 0; colonne < N; colonne++)
        {
            somma += mat[righe][colonne];
        }
    }

    return somma / (M * N);
}

int main()
{
    int matrice[M][N];

    CaricaMat(matrice);

    int minimo = Minimo(matrice);
    int massimo = Massimo(matrice);
    double media = Media(matrice);

    printf("Il valore minimo nella matrice è: %d\n", minimo);
    printf("Il valore massimo nella matrice è: %d\n", massimo);
    printf("La media dei valori nella matrice è: %.2f\n", media);

    return 0;
}
