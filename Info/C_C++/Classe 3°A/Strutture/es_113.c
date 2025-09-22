/*
author: Prandi Alessandro
date: 29/05/2023
es.
testo:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LUNG 20
#define DIM 9

typedef struct {
    int progressivo;
    char data[LUNG];
    char operazione;
    float importo;
} Movimenti;

int menu() {
    int opzione;
    printf("0 - esci\n");
    printf("1 - nuovo movimento\n");
    printf("2 - visualizza estratto conto\n");
    printf("3 - saldo finale\n");
    printf("4 - Visualizza: tutti i prelievi e il totale prelievi E tutti i versamenti e il totale versamenti\n");
    printf("scelta: ");
    scanf("%d", &opzione);
    return opzione;
}

void inserisciMov(Movimenti banca[], int n, float *saldo) {
    printf("inserisci la data del movimento: ");
    scanf("%s", banca[n].data);
    printf("inserisci il tipo di movimento(v per versamento p per prelievo): ");
    fflush(stdin);
    scanf("%c", &banca[n].operazione);
    if(banca[n].operazione== 'P' || banca[n].operazione== 'p') {
        printf("inserisci l'importo del prelievo: ");
        scanf("%f", &banca[n].importo);
        *saldo=*saldo-banca[n].importo;
        printf("\nil prelievo e stato effettuato il tuo saldo e ora di %f", *saldo);
    }else if(banca[n].operazione== 'V' || banca[n].operazione== 'v') {
    printf("\ninserisci l'importo del versamento: ");
    scanf("%f", &banca[n].importo);
    *saldo=*saldo +banca[n].importo;
    printf("ora il tuo saldo e' di: %.1f \n", *saldo);
}
banca[n].progressivo=n+1;
}

void scambio(Movimenti *a, Movimenti *b) {
    Movimenti c;
    c=*a;
    *a=*b;
    *b=c;
}

void ordinaData(Movimenti banca[], int n) {
    for(int sup=n-1; sup>0; sup--) {
        for(int k=0; k<sup; k++) {
            if(strcmp(banca[k].data, banca[k+1].data)>0) {
                scambio(&banca[k], &banca[k+1]);
            }
        }
    }
}

void VisMov(Movimenti banca[], int n, float saldo, float *totP, float *totV) {
    *totP=0;
    *totV=0;
    for(int k=0; k<n; k++) {
        printf("saldo = 0");
        if(banca[k].operazione== 'P' || banca[k].operazione== 'p') {
            printf("prelievo di: %f", banca[k].importo);
            *totP=*totP+1;
        } else if(banca[k].operazione== 'V' || banca[k].operazione== 'v') {
            printf("versamento di: %f", banca[k].importo);
            *totV=*totV+1;
        }
    }
}

int main() {
    Movimenti banca[DIM];
    int scelta, n=0;
    float saldo=0;
    float totP=0;
    float totV=0;
    do {
        scelta=menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            inserisciMov(banca, n, &saldo);
            ordinaData(banca, n);
            n++;
            break;
        case 2:
            VisMov(banca, n, saldo, &totP, &totV);
            break;
        case 3:
            printf("\nil sado attuale e' di: %.1f", saldo);
            break;
        case 4:
            VisMov(banca, n, saldo, &totP, &totV);
            printf("\nil totale dei versamenti e': %.1f", totV);
            printf("\nil totale dei prelievi e': %.1f", totP);
            break;
        }
    } while(scelta!=0);

    return 0;
}
