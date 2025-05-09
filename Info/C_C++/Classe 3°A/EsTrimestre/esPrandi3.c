/*
author: Prandi Alessandro
date: 7/12/2022
es. Prandi3
testo
*/

#include <stdio.h>
#include <stdlib.h>
#define DIVIS 4
#define DIVIS_SEC 400
#define SEC 100
#define GREG 1582

int main() {
    int anno;

    printf("inserisci un anno:\n");
    scanf("%d", &anno);
    if (anno >= GREG ) {
        if (anno % SEC == 0) {
            printf("\ne un anno secolare");
            if (anno % DIVIS_SEC == 0)
                printf("\ne un anno bisestile");
            else
                printf("\nnon e un anno bisestile");
        } else if (anno % DIVIS == 0)
            printf("\ne bisestile ");
        else
            printf("\nnon e bisestile");
    } else
        printf("non e possibile sapere se e bisestile");

    return 0;

}
