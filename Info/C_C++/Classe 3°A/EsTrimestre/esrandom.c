/*
author: Prandi Alessandro
date: 30/11/2022
es. random
testo
generazione numeri casuali
*/

#include <stdio.h>
#include <stdlib.h> //contiene la funzione rand
#include <time.h> //gestisce gli intervalli di tempo

main(){
//imposta un tempo casuale
srand(time(NULL));

//numero casuale
int rl = rand();
printf("numero casuale:\n%d",rl);
//numero casuale massimo
printf("\nmax valore casuale:\n%d",RAND_MAX);
//numero casuale compreso tra 0 e 99
rl = rand() % 100;
printf("numero casuale (0-99):\n%d",rl);
}
