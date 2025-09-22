/*
author: Prandi Alessandro
date: 25/05/2023
es. 111
testo
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#define LUNG 50
#define DIM 100

typedef struct {
    char cognome[LUNG];
    char nome[LUNG];
    char sesso;
    char indirizzo[LUNG];
    char num[LUNG];
    int eta;
} Contatto;

/*int chiediDim() {
    int dim;
    printf("quante persone sono presenti nella rubrica?: ");
    scanf("%d", &dim);
    return dim;
}*/

int menu() {
    int opzione;
    printf("\nscegli una di queste opzioni: \n");
    printf("0 - esci\n");
    printf("1 - Inserisci nuovo elemento\n");
    printf("2 - Cerca elemento X\n");
    printf("3 - Visualizza tutto\n");
    printf("4 - Statistiche\n");
    printf("5 - Modifica dati elemento X\n");
    printf("6 - Incrementa l'età d’ogni elemento di 1\n");
    printf("Scelta: ");
    scanf("%d", &opzione);
    return opzione;
}

void scambio(Contatto *a, Contatto *b) {
    Contatto c;
    c=*a;
    *a=*b;
    *b=c;
}

void inserisciElem(Contatto rub[], int k) {
    printf("inserisci il nome: ");
    scanf("%s", rub[k].nome);
    printf("\ninserisci il cognome: ");
    scanf("%s", rub[k].cognome);
    printf("\ninserisci il sesso(M o F):");
    fflush(stdin);
    scanf("%c", &rub[k].sesso);
    printf("\ninserisci l'indirizzo: ");
    scanf("%s", rub[k].indirizzo);
    printf("\ninserisci il numero: ");
    scanf("%s", rub[k].num);
    printf("\ninserisci l'eta: ");
    scanf("%d", &rub[k].eta);
    if(k>0) {
        for(int sup=k; sup>0; sup--) {
            for(int j=0; j<sup; j++) {
                if(strcmp(rub[j].cognome, rub[j+1].cognome)>0) {
                    scambio(&rub[j], &rub[j+1]);
                } else if(strcmp(rub[j].cognome, rub[j+1].cognome)==0) {
                    if(strcmp(rub[j].nome, rub[j+1].nome)>0) {
                        scambio(&rub[j], &rub[j+1]);
                    }
                }
            }
        }
    }
}

void cercaPers(Contatto rub[], int k) {
    char pers[LUNG];
    printf("\ninserisci il cognome della persona che si vuole cercare: ");
    scanf("%s", pers);
    int cont=0;
    bool continua=true;
    while(cont<=k && continua==true) {
        if(strcmp(pers, rub[cont].cognome)==0) {
            printf("\necco i suoi dati: %s  %s  %c  %s  %s  %d", rub[cont].cognome, rub[cont].nome,
                   rub[cont].sesso, rub[cont].indirizzo, rub[cont].num, rub[cont].eta);
            continua=false;
        } else {
            if(strcmp(pers, rub[cont].cognome)<0){
                continua=false;
                printf("la persona non e' presente.\n");
            }
            cont++;
        }
    }
}

void stampaTutto(Contatto rub[], int k) {
    for(int j=0; j<k; j++) {
        printf("\n%s  %s  %c  %s  %s  %d", rub[j].cognome, rub[j].nome, rub[j].sesso, rub[j].indirizzo, rub[j].num, rub[j].eta);
    }
}

void statistiche(Contatto rub[], int k) {
    int etaF=0, contF=0;
    int etaM=0, contM=0;
    float etaMedF, etaMedM;
    for(int j=0; j<k; j++) {
        if(rub[j].sesso=='f' || rub[j].sesso=='F') {
            etaF=etaF+rub[j].eta;
            contF++;
        } else {
            etaM=etaM+rub[j].eta;
            contM++;
        }
    }
    if(contM==0) {
        printf("\nnon sono presenti maschi.\n");
    } else {
        etaMedM=(float)etaM/contM;
        printf("\nl'eta meida dei maschi e': %.1f", etaMedM);
    }
    if(contF==0) {
        printf("\nnon sono presenti femmine.\n");
    } else {
        etaMedF=(float)etaF/contF;
        printf("\nl'eta meida delle femmine e': %.1f", etaMedF);
    }
}

int opzioni() {
    int scelta;
    printf("\nscegliere cosa cambiare.\n");
    printf("0 - terminato\n");
    printf("1 - il sesso\n");
    printf("2 - l'indirizzo\n");
    printf("3 - il numero\n");
    printf("4 - l'eta\n");
    printf("scegli: ");
    scanf("%d", &scelta);
    return scelta;
}

void cambioDati(Contatto rub[], int k) {
    char Pers[LUNG];
    printf("\ninserisci il cognome della persona di cui si vuole cambiare dati: ");
    scanf("%s", Pers);
    int cont=0, scambio=0;
    bool continua=true;
    while(cont<=k && continua==true) {
        if(strcmp(Pers, rub[cont].cognome)==0) {
            do {
                scambio=opzioni();
                switch(scambio) {
                case 0:
                    break;
                case 1:
                    printf("\ninserisci il sesso(M o F): ");
                    fflush(stdin);
                    scanf("%c", &rub[cont].sesso);
                    break;
                case 2:
                    printf("\ninserisci l'indirizzo: ");
                    scanf("%s", rub[cont].indirizzo);
                    break;
                case 3:
                    printf("\ninserisci il numero: ");
                    scanf("%s", rub[cont].num);
                    break;
                case 4:
                    printf("\ninserisci l'eta: ");
                    scanf("%d", &rub[cont].eta);
                    break;
                }
            } while(scambio != 0);
        } else if(strcmp(rub[k].cognome, Pers)>0) {
            printf("\nla persona cercata non e' presente nella rubrica.");
            continua=false;
        }
        cont++;
    }
}

void incrementoAN(Contatto rub[], int k) {
    for(int j=0; j<=k; j++) {
        rub[j].eta = rub[j].eta + 1;
    }
}

int main() {
    Contatto rub[DIM];
    int scelta, k=0;
    do {
        scelta=menu();
        switch(scelta) {
        case 0:
            break;
        case 1:
            if(k<DIM) {
                inserisciElem(rub, k);
                k++;
            }else
                printf("rubrica piena.\n");
            break;
        case 2:
            cercaPers(rub, k);
            break;
        case 3:
            stampaTutto(rub, k);
            break;
        case 4:
            statistiche(rub, k);
            break;
        case 5:
            cambioDati(rub, k);
            break;
        case 6:
            incrementoAN(rub, k);
            break;
        }
    } while(scelta != 0);
    return 0;
}
