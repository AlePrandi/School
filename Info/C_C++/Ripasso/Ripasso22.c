/*
author: Alessandro Prandi
date:
es.
testo:
*/
#include <stdio.h>
#include <stdlib.h>
#define DIM_MAX 10

int chiediDim(int n_max)
{
    int x;
    do
    {
        printf("Inserisci grandezza della matrice: ");
        scanf("%d", &x);
    } while (x < 0 || x > n_max);
    return x;
}

void caricaMat(int mat[][DIM_MAX], int n)
{
    for (int r = 0; r < n; r++)
    {
        for (int c = 0; c < n; c++)
        {
            printf("Inserisci un valore: \n");
            scanf("%d", &mat[r][c]);
        }
    }
}

int calcDiagP(int mat[][DIM_MAX], int n)
{
    int sommaPrin = 0;
    int k = 0;
    for (int k = 0; k < n; k++)
    {
        sommaPrin = sommaPrin + mat[k][k];
    }
    return sommaPrin;
}

int calcDiagS(int mat[][DIM_MAX], int n)
{
    int sommaSec = 0;
    int k = 0;
    for (int k = 0; k < n; k++)
    {
        sommaSec = sommaSec + mat[k][n - k - 1];
        k++;
    }
    return sommaSec;
}

int main()
{
    int mat[DIM_MAX][DIM_MAX];
    int n = chiediDim(DIM_MAX);
    caricaMat(mat, n);
    int Dprin = calcDiagP(mat, n);
    int Dsec = calcDiagS(mat, n);
    printf("Somma diagonale principale: %d \n", Dprin);
    printf("Somma diagonale secondaria: %d \n", Dsec);
}
