/*programma che intercetta i tasti premuti */

#include <conio.h>      //kbhit getch
#include <stdio.h>
#include <stdbool.h>
#include "GraficaPrandi.h"

#define FUNZ 224
#define SU 72
#define GIU 80
#define DX 77
#define SX 75
#define ESC 27
#define CANC 8
#define FINE 79
#define WIN_HEIGTH 30
#define WIN_WIDTH 120
#define RED 12
#define BLU 9
#define NERO 0

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
    //(*p).carattere
    p->carattere = carattere;
    p->pos.x = x;
    p->pos.y = y;
    p->colore = colore;
}

void disegnaOggetto(Oggetto p) {
    unsigned short oldColor = getTextColor(); //salvo il colore attuale

    gotoxy(p.pos.x, p.pos.y);   // mi posiziono
    setTextColor(p.colore);     //setto il colore
    printf("%c", p.carattere);  //disegno il carattere
    setTextColor(oldColor);     //ripristino il colore precedente
}

void saleOggetto(Oggetto *p) {
    if (p->pos.y > 0)
        p->pos.y--;
    else {}
    //messaggio di errore o ...
}

void sxOggetto(Oggetto *p) {
    if (p->pos.x > 0)
        p->pos.x--;
}

void dxOggetto(Oggetto *p) {
    if (p->pos.x > 0)
        p->pos.x++;
}

void scendeOggetto(Oggetto *p) {
    if (p->pos.y > 0)
        p->pos.y++;

}

void cancella(Oggetto *p) {
    gotoxy(p->pos.x, p->pos.y);
    setTextColor(NERO);
}

bool isTastoFunzione(unsigned char c) {
    return (c == 224 || c == 0); //224 per tasti frecce e Fine, 0 per tasti F1, F2,...
}

int main() {
    setConsoleDimensions(WIN_WIDTH, WIN_HEIGTH);
    Oggetto p1, p2;

    creaOggetto(&p1, WIN_WIDTH / 2, WIN_HEIGTH / 2, 'o', RED);
    creaOggetto(&p2,  2, 2, '*', BLU);

    int velocita = 100;
    unsigned char a; //codice ASCII tasto premuto
    bool esci; //per uscire dal ciclo lettura tasti
    esci= false;

    cursor_hide();
    //ciclo fino a quando non premo il tasto ESC=27 (è tasto funzione)
    while (!esci) {
        disegnaOggetto(p1);
        disegnaOggetto(p2);
        //se premo un tasto vedo che carattere ho premuto
        //altrimenti continuo nel ciclo
        if (kbhit() == true)    {
            a = getch();
            // se e' un tasto funzione come F1, F2 o sono le frecce o Home e End sono composto da 2 byte
            //rimane il secondo byte che viene letto nella if successiva
            gotoxy(0,25);
            printf("ASCII= %3d  Tasto= %c\n", a, a); //vedo che carattere ho premuto
            if (isTastoFunzione(a)) { //è un tasto funzione
                //leggo il secondo byte contenente il tipo di tasto funzione premuto
                a = getch();
                printf("ASCII=%3d  Tasto=%c\n", a, a); // se voglio conoscere codice ascii di un tasto
                switch (a)	     {
                case SU: // freccia su
                    cancella(&p1);
                    saleOggetto(&p1);
                    printf("su \n");
                    break;
                case GIU: // freccia giu
                    cancella(&p1);
                    scendeOggetto(&p1);
                    printf("giu\n");
                    break;
                case SX: // freccia sx
                    cancella(&p1);
                    sxOggetto(&p1);
                    printf("sx \n");
                    break;
                case DX: // freccia dx
                    cancella(&p1);
                    dxOggetto(&p1);
                    printf("dx \n");
                    break;
                    if(p1.pos.x == WIN_WIDTH/2 - 1)
                        gotoxy((p1.pos.x - p1.pos.x), p1.pos.y);

                }
            } else {    //non è un tasto funzione
                switch (a) {
                case ESC:  //tasto ESC
                    esci = true;
                    break;
                }
            }
        }
    }
    return 0;
}

