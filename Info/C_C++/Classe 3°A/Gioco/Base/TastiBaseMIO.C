/*programma che intercetta i tasti premuti */

#include <conio.h>      //kbhit getc
#include <stdio.h>
#include <stdbool.h>
#include "utility.h"

#define FUNZ 224
#define SU 72
#define GIU 80
#define DX 77
#define SX 75
#define ESC 27
#define FINE 79
#define WIN_HEIGTH 30
#define WIN_WIDTH 120
#define RED 12
#define BLU 9

bool isTastoFunzione(unsigned char c){
    return (c == 224 || c == 0); //224 per tasti frecce e Fine, 0 per tasti F1, F2,...
}

main() {
    unsigned char a; //codice ASCII tasto premuto
    bool esci; //per uscire dal ciclo lettura tasti
    esci = false;

    cursor_hide();
    //ciclo fino a quando non premo il tasto ESC=27 (non è tasto funzione come le frecce) o Fine 224+79(è tasto funzione)
    setConsoleDimensions(WIN_WIDTH,WIN_HEIGTH);
    while (!esci) {
        //se premo un tasto vedo che carattere ho premuto
        //altrimenti continuo nel ciclo
        if (kbhit() == true)    {
            a = getch();
            // se e' un tasto funzione come Ins, Canc o sono le frecce o Home e End sono composto da 2 byte
            //rimane il secondo byte che viene letto nella if successiva
            printf("ASCII= %3d  Tasto = %c\n", a, a); //vedo che carattere ho premuto
            if (isTastoFunzione(a)) { //è un tasto funzione
                //leggo il secondo byte contenente il tipo di tasto funzione premuto
                a = getch();
                printf("ASCII= %3d  Tasto funzione= %c\n", a, a); // se voglio conoscere codice ascii del tasto funzione
                switch (a) {
                case SU: // freccia su
                    printf("su\n");
                    break;
                case GIU: // freccia giu
                    printf("giu\n");
                    break;
                case SX: // freccia sx
                    printf("sx\n");
                    break;
                case DX: // freccia dx
                    printf("dx\n");
                    break;
                case FINE: // tasto fine
                    esci = true;
                    break;
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
}
