/*
author: Prandi Alessandro
date: Tutta l'estate
es. Campo Minato
testo
Regole:
il proprio giocatore color verde deve riuscire a mangiar il maggior numero di obbiettivi in rosso
senza toccare gli ostacoli
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
#define WIN_WIDTH 40 // X
#define RED 68
#define BLU 17
#define NERO 0
#define GREEN 170
#define GIALLO 102
#define LUNG_MAX 25
#define PUNT_MAX 5000

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

void salePlayer(Oggetto *p) {
    if (p->pos.y > 0)
        p->pos.y--;
}

void sxPlayer(Oggetto *p) {
    if (p->pos.x > 0)
        p->pos.x--;
}

void dxPlayer(Oggetto *p) {
    if (p->pos.x < WIN_WIDTH)
        p->pos.x++;
}

void scendePlayer(Oggetto *p) {
    if (p->pos.y < WIN_HEIGTH)
        p->pos.y++;

}

void cancella(Oggetto *p) {
    rettangoloPienoColore(p->pos.x, p->pos.y,1,1,' ',NERO);
}

bool eFunzMov(unsigned char c) {
    return (c == 224 || c == 0);
}

bool timer(int sec){
    if(sec <= 0)
        return true;
    else
    while(sec > 0){
        Sleep(1000);
        sec--;
    }
}

void Introduzione() {
    gotoxy(WIN_WIDTH / 2 - 14, WIN_HEIGTH / 2 - 2);
    printf("Benvenuto su questo gioco");
    gotoxy(WIN_WIDTH / 2 - 18, WIN_HEIGTH / 2);
    printf("Per muoverti utilizza le freccette!");
    gotoxy(WIN_WIDTH / 2 - 9, WIN_HEIGTH / 2 + 2);
    printf("Premi q per uscire!");
    gotoxy(WIN_WIDTH / 2 - 15, WIN_HEIGTH / 2 + 4);
    printf("Creato da: Alessandro Prandi");
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
    char nomeFile[LUNG_MAX] = "punteggiCM.dat";
    if ((fp = fopen(nomeFile,"a"))!= NULL) {
        fprintf(fp,"Punteggio: %d \n", punti);
        fclose(fp);
    } else {
        fp = fopen(nomeFile,"w");
        fprintf(fp,"Punteggio: %d \n", punti);
    }
}

void Istruzioni(){
gotoxy(WIN_WIDTH / 2 - 15, WIN_HEIGTH / 2 - 2);
printf("In questo gioco l'obbiettivo e'");
gotoxy(WIN_WIDTH / 2 - 18, WIN_HEIGTH / 2);
printf("catturare piu' obbiettivi possibile");
gotoxy(WIN_WIDTH / 2 - 20, WIN_HEIGTH / 2 + 2);
printf("senza toccare ne i bordi ne gli ostacoli");
Sleep(5000);
clrscr();
}

int main() {
    cursor_hide();
    srand(time(NULL));
    setConsoleDimensions(WIN_WIDTH, WIN_HEIGTH);
    Oggetto player, Obb, ostacolo[LUNG_MAX];

    unsigned char Tasto;
    bool esci;
    int Obb_x, Obb_y,N_ost;
    do {
        Obb_x = 1 + rand() % WIN_WIDTH - 1; //coordinate Obbiettivo
        Obb_y = 1 + rand() % WIN_HEIGTH - 1;
    } while(Obb_x == WIN_WIDTH / 2 || Obb_y == WIN_HEIGTH / 2 || Obb_x == 0 || Obb_x == WIN_WIDTH - 1 || Obb_y == 0 || Obb_y == WIN_HEIGTH - 1);
    int punteggio = 0;
    esci= false;
    N_ost = 0;
    Introduzione();

    Istruzioni();

    Bordi();

    creaOggetto(&player, WIN_WIDTH / 2, WIN_HEIGTH / 2,' ', GREEN);
    creaOggetto(&Obb, Obb_x, Obb_y,' ', RED);

    while (!esci) {
        disegnaOggetto(player);
        disegnaOggetto(Obb);
        if (kbhit() == true)    {
            Tasto = getch();
            if (eFunzMov(Tasto)) {
                Tasto = getch();
                switch (Tasto) {
                case SU:
                    cancella(&player);
                    salePlayer(&player);
                    break;
                case GIU:
                    cancella(&player);
                    scendePlayer(&player);
                    break;
                case SX:
                    cancella(&player);
                    sxPlayer(&player);
                    break;
                case DX:
                    cancella(&player);
                    dxPlayer(&player);
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

        if(Obb.pos.x == player.pos.x && Obb.pos.y == player.pos.y) {
            punteggio = punteggio + 100;
            cancella(&Obb);
            N_ost++;
            do {
                Obb_x = 1 + rand() % WIN_WIDTH - 1;
                Obb_y = 1 + rand() % WIN_HEIGTH - 1;
            } while(Obb_x == player.pos.x || Obb_y == player.pos.y || Obb_x == 0 || Obb_x == WIN_WIDTH - 1 || Obb_y == 0 || Obb_y == WIN_HEIGTH - 1);

            creaOggetto(&Obb, Obb_x, Obb_y,' ',RED);

            do {
                ostacolo[N_ost].pos.x = 1 + rand() % WIN_WIDTH - 1;
                ostacolo[N_ost].pos.y = 1 + rand() % WIN_HEIGTH - 1;
            } while(ostacolo[N_ost].pos.x == player.pos.x || ostacolo[N_ost].pos.y == player.pos.y
                    || ostacolo[N_ost].pos.x == 0 || ostacolo[N_ost].pos.x == WIN_WIDTH - 1
                    || ostacolo[N_ost].pos.y == 0 || ostacolo[N_ost].pos.y == WIN_HEIGTH - 1
                    || ostacolo[N_ost].pos.x == Obb_x || ostacolo[N_ost].pos.y == Obb_y);
            creaOggetto(&ostacolo[N_ost],ostacolo[N_ost].pos.x, ostacolo[N_ost].pos.y,'*', GIALLO);
            disegnaOggetto(ostacolo[N_ost]);
        }

        for(int n = 0;n < N_ost;n++){
        if(player.pos.x == ostacolo[n].pos.x && player.pos.y == ostacolo[n].pos.y){
            clrscr();
            gotoxy(WIN_WIDTH / 2 - 15, WIN_HEIGTH / 2 - 1);
            printf("Non puoi toccare gli ostacoli.");
            gotoxy(WIN_WIDTH / 2 - 10, WIN_HEIGTH / 2 + 1);
            printf("Hai perso!");
            Sleep(1500);
            clrscr();
            esci = true;
        }
        }
        if(punteggio == PUNT_MAX) {
            gotoxy(WIN_WIDTH / 2 - 5, WIN_HEIGTH / 2);
            printf("Hai vinto!");
            Sleep(1000);
            clrscr();
            esci = true;
        }

        if(player.pos.x == 0 || player.pos.x == WIN_WIDTH - 1 || player.pos.y == 0 || player.pos.y == WIN_HEIGTH - 1 ) {
            gotoxy(WIN_WIDTH / 2 - 16, WIN_HEIGTH / 2);
            printf("Non puoi toccare il bordo, hai perso!");
            Sleep(1500);
            clrscr();
            esci = true;
        }
    }
    for(int k = 0; k < N_ost; k++) {
        cancella(&player);
        cancella(&ostacolo[k]);
    }
    cancella(&Obb);
    gotoxy(WIN_WIDTH / 2 - 10,WIN_HEIGTH / 2);
    printf("Punteggio finale: %d", punteggio);
    salvaPunteggio(punteggio);
    for(int i = 0;i < 5;i++){
        printf("\n");
    }
    return 0;
}

