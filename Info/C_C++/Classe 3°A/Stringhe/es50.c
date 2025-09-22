/*
author: Prandi Alessandro
date: 10/04/2023
es. 50
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define LUNG_MAX 100
#define MAX_CAR 126
#define MIN_CAR 32

void stringa_rand(char s[], int n) {

    srand(time(NULL));
    for (int k = 0; s[k] != '\0'; k++) {
        s[k]=MIN_CAR + rand() % (MAX_CAR + 1 - MIN_CAR);
    }
    s[LUNG_MAX] = '\0';
}

int main() {
    char s[LUNG_MAX];

    stringa_rand(s, LUNG_MAX);

    printf("La stringa casuale generata e': %s", s);

    return 0;
}
