/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MIN 1
#define MAX 6

float cCred() {
    float cred;
    do {
        printf("inserire il credito a disposizione: \n");
        scanf("%f", &cred);
    } while (cred <= 0);
    return (cred);

}
void giocata(float c, float punt, float *conc) {
    int t1, t2;
    srand(time(NULL));
    t1 = MIN + rand() % (MAX + 1 - MIN);
    printf("primo numero uscito %d\n", t1);
    t2 = MIN + rand() % (MAX + 1 - MIN);
    printf("secondo numero uscito %d\n", t2);
    if (t1 == t2) {
        *conc = c + punt * 6;
    } else {
        *conc = c - punt;
    }
}
float cPunt(float c) {
    float punt; //puntata
    do {
        printf("inserire la puntata per questa partita: \n");
        scanf("%f", &punt);
    } while (punt > c);
}
int main() {
    int cont = 0; //numfinaletiri
    float c, punt, conc; //credito conclusione
    char risp;
    c=cCred();
    do {
        punt=cPunt(c);
        giocata(c, punt, &conc);
        printf("vuoi ancora continuare? \n");
        scanf("%s", &risp);
        cont = cont + 1;
    } while (risp == 's' || conc == 0);
    printf("credito finale %f\n", conc);
    printf("numero di tiri finali %f", cont);

    return 0;
}
