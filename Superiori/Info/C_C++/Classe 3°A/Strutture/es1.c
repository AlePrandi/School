/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define DIM 3
#define LUNG 30
#define NMAXSTUDENTI 35

typedef struct{
    int scritto;
    int orale;
    int pratico;
}TipoVoti;

typedef struct votiStudente{
    char nome[LUNG];
    TipoVoti voti;
    float media;
}VotiStudente; //ATTENTA

void visDati(VotiStudente s){
    printf("%s ", s.nome);
    print("%d ", s.voti.orale);
   /* for (int k=0; k < DIM; k++)
        printf("%d ", s.voti[k]);*/
    printf("%.2f ", s.media);
}
main(){

    struct votiStudente s1, s2;
    int somma = 0;

    strcpy(s1.nome, "luca");
    s1.voti[0]= 6;
    s1.voti[1]= 7;
    s1.voti[2]= 5;

    for(int k=0; k<DIM; k++){
        somma+=s1.voti[k];
    }
    s1.media = (float)somma/DIM;
    visDati (s1);

    VotiStudente pagella[NMAXSTUDENTI];//vettore di strutture
    for (int k = 0; k < NMAXSTUDENTI; k++){
        scanf("%s", pagella[k].nome);
        somma =0;
        for (int i= 0; i < DIM; i++){
            scanf("%d", &pagella[k].voti[i]);
        }
    }
}
