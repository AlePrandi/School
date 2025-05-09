/*
author: Prandi Alessandro
date: 14/02/2023
es. 140
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN_min 97
#define MAX_min 122
#define MIN_MAIU 65
#define MAX_MAIU 90

int main() {
    srand(time(NULL));
    int lung, cont;
    char iniz, lett;
    printf("inserire la lunghezza del nome dell'azienda: \n");
    scanf("%d", &lung);
    iniz = MIN_MAIU + rand() % (MAX_MAIU + 1 - MIN_MAIU);
    printf("%c", iniz);
    for (cont = 1; cont < lung; cont++) {
        lett = MIN_min + rand() % (MAX_min + 1 - MIN_min);
        printf("%c", lett);
    }
    return 0;
}
