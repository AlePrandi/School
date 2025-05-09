/*
author: Prandi Alessandro
date: Tutta l'estate
es. Snake
testo
*/

#include <conio.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include "GraficaPrandi.h"
#define FUNZ 224
#define SU 72
#define GIU 80
#define DX 77
#define SX 75
#define QUIT 113
#define CANC 8
#define FINE 79
#define WIN_HEIGTH 30 // Y
#define WIN_WIDTH 120 // X
#define RED 68
#define BLU 17
#define NERO 0
#define GREEN 170
#define PUNT_MAX 10000
#define MAX_SERP 6
#define LUNG_MAX 25

typedef struct {
    int x;
    int y;
} Posizione;

typedef struct {
    Posizione pos;
    char carattere;
    unsigned short colore;
} Oggetto;

void creaOggetto(Oggetto *p, int x, int y, char carattere, unsigned short colore) {
    p->carattere = carattere;
    p->pos.x = x;
    p->pos.y = y;
    p->colore = colore;
}

void disegnaOggetto(Oggetto p) {
    unsigned short oldColor = getTextColor();
    rettangoloPienoColore(p.pos.x, p.pos.y,1,1,p.carattere,p.colore);
    setTextColor(oldColor);
}

void saleTesta(Oggetto *p) {
    if (p->pos.y > 0)
        p->pos.y--;
}

void sxTesta(Oggetto *p) {
    if (p->pos.x > 0)
        p->pos.x--;
}

void dxTesta(Oggetto *p) {
    if (p->pos.x < WIN_WIDTH)
        p->pos.x++;
}

void scendeTesta(Oggetto *p) {
    if (p->pos.y < WIN_HEIGTH)
        p->pos.y++;

}

void cancella(Oggetto *p) {
    rettangoloPienoColore(p->pos.x, p->pos.y,1,1,' ',NERO);
}

bool eFunzMov(unsigned char c) {
    return (c == 224 || c == 0);
}

void Introduzione() {
    gotoxy(WIN_WIDTH / 2 - 10, WIN_HEIGTH / 2 - 1);
    printf("Benvenuto su Snake.c");
    gotoxy(WIN_WIDTH / 2 - 18, WIN_HEIGTH / 2 + 1);
    printf("Per muoverti utilizza le freccette!");
    gotoxy(WIN_WIDTH / 2 - 9, WIN_HEIGTH / 2 + 3);
    printf("Tasto q per uscire!");
    Sleep(3000);
    clrscr();
    gotoxy(WIN_WIDTH / 2 - 10, WIN_HEIGTH / 2);
    printf("Buon divertimento!");
    Sleep(2000);
    clrscr();
}

void Bordi() {
    rettangoloPienoColore(0,0,WIN_WIDTH, 1,' ', BLU);
    rettangoloPienoColore(0,0,1,WIN_HEIGTH,' ', BLU);
    rettangoloPienoColore(WIN_WIDTH - 1,0,1,WIN_HEIGTH,' ',BLU);
    rettangoloPienoColore(0,WIN_HEIGTH - 1,WIN_WIDTH,1,' ',BLU);
}

void salvaPunteggio(int punti) {
    FILE *fp;
    char nomeFile[LUNG_MAX] = "punteggiSnake.dat";
    if ((fp = fopen(nomeFile,"a"))!= NULL) {
        fprintf(fp,"Punteggio: %d \n", punti);
        fclose(fp);
    } else {
        fp = fopen(nomeFile,"w");
        fprintf(fp,"Punteggio: %d \n", punti);
    }
}

int main() {
    cursor_hide();
    srand(time(NULL));
    setConsoleDimensions(WIN_WIDTH, WIN_HEIGTH);
    Oggetto serpente[MAX_SERP], mela;

    unsigned char Tasto;
    bool esci;
    int melax, melay;
    do {
        melax = 1 + rand() % WIN_WIDTH - 1; //coordinate mela
        melay = 1 + rand() % WIN_HEIGTH - 1;
    } while(melax == WIN_WIDTH / 2 || melay == WIN_HEIGTH / 2 || melax == 0 || melax == WIN_WIDTH - 1 || melay == 0 || melay == WIN_HEIGTH - 1);
    int punteggio = 0;
    esci= false;

    Introduzione();

    Bordi();

    for(int k = 0; k < MAX_SERP; k++) {
        creaOggetto(&serpente[k], WIN_WIDTH / 2, WIN_HEIGTH / 2 + k,' ', GREEN);
    }
    creaOggetto(&mela, melax, melay,' ', RED);

    while (!esci) {
        for(int k = 0; k < MAX_SERP; k++) {
            disegnaOggetto(serpente[k]);
        }
        disegnaOggetto(mela);
        if (kbhit() == true)    {
            Tasto = getch();
            if (eFunzMov(Tasto)) {
                Tasto = getch();
                switch (Tasto) {
                case SU:
                    cancella(&serpente[MAX_SERP-1]);
                    saleTesta(&serpente[0]);
                    for(int i=1; i<MAX_SERP; i++) {
                        if(serpente[i].pos.x == serpente[0].pos.x) {
                            saleTesta(&serpente[i]);
                        } else {
                            if(serpente[i].pos.x > serpente[0].pos.x) {
                                sxTesta(&serpente[i]);
                            } else {
                                dxTesta(&serpente[i]);

                            }
                        }
                    }
                    break;
                case GIU:
                    if(serpente[0].pos.y >= serpente[1].pos.y) {
                        cancella(&serpente[MAX_SERP-1]);
                        scendeTesta(&serpente[0]);
                        for(int i=1; i<MAX_SERP; i++) {
                            if(serpente[i].pos.x == serpente[0].pos.x) {
                                scendeTesta(&serpente[i]);
                            } else {
                                if(serpente[i].pos.x > serpente[0].pos.x) {
                                    sxTesta(&serpente[i]);
                                } else {
                                    dxTesta(&serpente[i]);

                                }
                            }
                        }
                    }
                    break;
                case SX:
                    cancella(&serpente[MAX_SERP-1]);
                    sxTesta(&serpente[0]);
                    for(int i=1; i<MAX_SERP; i++) {
                        if(serpente[i].pos.y == serpente[0].pos.y) {
                            sxTesta(&serpente[i]);
                        } else if(serpente[i].pos.y > serpente[0].pos.y) {
                            saleTesta(&serpente[i]);
                        } else {
                            scendeTesta(&serpente[i]);
                        }
                    }
                    break;
                case DX:
                    cancella(&serpente[MAX_SERP-1]);
                    dxTesta(&serpente[0]);
                    for(int i=1; i<MAX_SERP; i++) {
                        if(serpente[i].pos.y == serpente[0].pos.y) {
                            dxTesta(&serpente[i]);
                        } else {
                            if(serpente[i].pos.y > serpente[0].pos.y) {
                                saleTesta(&serpente[i]);
                            } else {
                                scendeTesta(&serpente[i]);
                            }
                        }
                    }
                    break;
                }
            } else {
                switch (Tasto) {
                case QUIT:
                    clrscr();
                    gotoxy(WIN_WIDTH / 2 - 8, WIN_HEIGTH / 2);
                    printf("Partita terminata!");
                    Sleep(2000);
                    esci = true;
                    break;

                default:
                    gotoxy(WIN_WIDTH - 30,27);
                    printf("Tasto non Valido \n");
                    gotoxy(WIN_WIDTH - 30,28);
                    printf("Usare le frecce per muoversi");
                    Sleep(1500);
                    clrscr();
                    Bordi();
                }
            }
        }

        if(mela.pos.x == serpente[0].pos.x && mela.pos.y == serpente[0].pos.y) {
            punteggio = punteggio + 100;
            /*
                        MAX_SERP++;
                        switch(Tasto) {
                        case SU:
                            creaOggetto(&serpente[MAX_SERP - 1], serpente[MAX_SERP - 2].pos.x, serpente[MAX_SERP - 2].pos.y + 1,' ', GREEN);
                        case GIU:
                            creaOggetto(&serpente[MAX_SERP - 1], serpente[MAX_SERP - 2].pos.x, serpente[MAX_SERP - 2].pos.y - 1,' ', GREEN);
                        case SX:
                            creaOggetto(&serpente[MAX_SERP - 1], serpente[MAX_SERP - 2].pos.x + 1, serpente[MAX_SERP - 2].pos.y,' ', GREEN);
                        case DX:
                            creaOggetto(&serpente[MAX_SERP - 1], serpente[MAX_SERP - 2].pos.x - 1, serpente[MAX_SERP - 2].pos.y,' ', GREEN);
                        }
            */
            cancella(&mela);
            do {
                melax = 1 + rand() % WIN_WIDTH - 1;
                melay = 1 + rand() % WIN_HEIGTH - 1;
            } while(melax == serpente[0].pos.x || melay == serpente[0].pos.y || melax == 0 || melax == WIN_WIDTH - 1 || melay == 0 || melay == WIN_HEIGTH - 1);

            creaOggetto(&mela, melax, melay,' ',RED);
        }

        if(punteggio == PUNT_MAX) {
            gotoxy(WIN_WIDTH / 2 - 5, WIN_HEIGTH / 2);
            printf("Hai vinto!");
            Sleep(1000);
            clrscr();
            esci = true;
        }

        if(serpente[0].pos.x == 0 || serpente[0].pos.x == WIN_WIDTH - 1 || serpente[0].pos.y == 0 || serpente[0].pos.y == WIN_HEIGTH - 1 ) {
            gotoxy(WIN_WIDTH / 2 - 16, WIN_HEIGTH / 2);
            printf("Non puoi toccare il bordo, hai perso!");
            Sleep(1500);
            clrscr();
            esci = true;
        }
    }
    for(int k = 0; k < MAX_SERP; k++) {
        cancella(&serpente[k]);
    }
    cancella(&mela);
    gotoxy(WIN_WIDTH / 2 - 10,WIN_HEIGTH / 2);
    printf("Punteggio finale: %d", punteggio);
    salvaPunteggio(punteggio);
    printf("\n");
    printf("\n");
    printf("\n");
    return 0;
}
