/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    float n1, n2, s, med, sTot;
    FILE *fp;

    fp = fopen("sommecoppie.txt", "w");
    if (fp == NULL)    {
        printf("file non esistente");
    }    else    {
        int k = 0;
        sTot = 0;
           do     {
            printf("inserisci la coppia di numeri (separati con uno spazio, esempio: 4 6): ");
            scanf("%f %f", &n1, &n2);
            s = n1 + n2;
            if (n1 != 0 && n2 != 0) {
                k++;
                fprintf(fp, "%.2f\n", s);
                sTot += s;
            }
        }while (n1 != 0 && n2 != 0);
        if(k != 0){
            med = sTot / k;
            fprintf(fp, "\nla media delle somme e' %.2f\n", med);
        }
        fclose(fp);
    }
    return 0;
}
