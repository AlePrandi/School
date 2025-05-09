#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Maiusc(char *s, char prec)
{
    int k, j;
    j = 0;
    if (*s >= 'a' && *s <= 'z')
    {
        if (prec == '?' || prec == '.' || prec == '!')
        {
            *s = *s - 32;
        }
    }
}

void Minus(char *s, char prec)
{
    int k, j;
    j = 0;
    if (*s >= 'A' && *s <= 'Z')
    {
        if (prec == ':' || prec == ',' || prec == ';')
        {
            *s = *s + 32;
        }
    }
}

int main()
{
    char *lettera, lprec;
    char *Nomefile = "testo.txt";
    int cont = 0;
    FILE *fp, *fp1;

    fp = fopen("testo.txt", "r");
    fp1 = fopen("temp.txt", "w");
    if (fp == NULL)
    {
        printf("file non esistente");
    }
    else
    {
        while (fscanf(fp, "%c", lettera[cont]) != EOF)
        {
            if (cont == 0)
            {
                lprec = lettera[cont];
            }
            else
            {
                Minus(&lettera[cont], lprec);
                Maiusc(&lettera[cont], lprec);
                lprec = lettera[cont];
                fprintf(fp1, "%c", lettera[cont]);
                cont++;
            }
        }
    }
    remove(Nomefile);
    rename('temp.txt', Nomefile);
    fclose(fp);
    fclose(fp1);
    return 0;
}
