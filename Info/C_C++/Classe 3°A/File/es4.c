/*
author: Prandi Alessandro
date: 07/05/2023
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>

int main() {

    FILE *fp;
    FILE *fp1;
    float num1,num2;
    char operaz;
    float ris;

    fp = fopen("operazioni.txt", "r");
    fp1 = fopen("risultati.txt", "w");
    if (fp == NULL || fp1 == NULL) {
        printf("problemi con i file\n");
    } else {

        while(fscanf(fp, "%f%c%f", &num1, &operaz, &num2) != EOF) {

            switch(operaz) {

            case '+':
                ris = num1 + num2;
                break;

            case '-':
                ris = num1 - num2;
                break;

            case '*':
                ris = num1 * num2;
                break;

            case '/':
                ris = num1 / num2;
                break;
            }
            fprintf(fp1,"%.2f\n", ris);
        }
    }
    fclose(fp);
    fclose(fp1);
    return 0;
}
