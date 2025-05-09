#include "utility.h"  //inserire il percorso relativo corretto
#include <time.h>
//disegna un carattere car nella posizione (x,y)
void punto(int x, int y, char car);

//disegna un carattere car nella posizione (x,y) del colore color
void puntoColore(int x, int y, char car, int color);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
void riga(int x, int y, int lung, char car);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void rigaColore(int x, int y, int lung, char car, int color);

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando per ciauscun carattere un colore casuale tra i 16 possibili a partire dal colore base
void rigaColoriCasuali(int x, int y, int lung, char car, int coloreBase);

//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
void colonna(int x, int y, int lung, char car);

//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void colonnaColore(int x, int y, int lung, char car, int color);

//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoPieno(int x, int y, int l, char car);

//disegna un quadrato pieno di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoPienoColore(int x, int y, int l, char car, int color);

//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car
void quadratoVuoto(int x, int y, int l, char car);

//disegna un quadrato vuoto di lato l con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void quadratoVuotoColore(int x, int y, int l, char car, int color);

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloPieno(int x, int y, int b, int h, char car);

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloPienoColore(int x, int y, int b, int h, char car, int color);

//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloVuoto(int x, int y, int b, int h, char car);

//disegna un rettangolo vuoto di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloVuotoColore(int x, int y, int b, int h, char car, int color);


//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car
void triangolo(int x, int y, int h, char car);

//disegna un triangolo pieno di altezza h
//con vertice nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void triangoloColore(int x, int y, int h, char car, int color);

//DEFINIZIONE delle PROCEDURE

//disegna un carattere car nella posizione (x,y)
void punto(int x, int y, char car) {
    gotoxy(x, y);
    printf("%c", car);
}

//disegna un carattere car nella posizione (x,y) del colore color
void puntoColore(int x, int y, char car, int color) {
    int current = getTextColor();
    setTextColor(color);
    gotoxy(x, y);
    printf("%c", car);
    setTextColor(current);
}
//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
void riga(int x, int y, int lung, char car) {
    gotoxy(x, y);
    for(int k = 0; k < lung; k++) {
        printf("%c", car);
    }
}

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void rigaColore(int x, int y, int lung, char car, int color) {
    int current = getTextColor();
    setTextColor(color);
    gotoxy(x, y);
    for(int k = 0; k < lung; k++) {
        printf("%c", car);
    }
    setTextColor(current);
}

//disegna una riga di lung caratteri car a partire dalla posizione (x,y)
//utilizzando per ciauscun carattere un colore casuale tra i 16 possibili a partire dal colore base
void rigaColoriCasuali(int x, int y, int lung, char car, int coloreBase) {
    srand(time(NULL));
    coloreBase = coloreBase + rand() % 16;
    int current = getTextColor();
    setTextColor(coloreBase);
    gotoxy(x, y);
    for(int k = 0; k < lung; k++) {
        printf("%c", car);
    }
    setTextColor(current);
}
//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
void colonna(int x, int y, int lung, char car) {
    gotoxy(x, y);
    for(int k = 0; k < lung; k++) {
        printf("%c", car);
    }
}
//disegna una colonna di lung caratteri car a partire dalla posizione (x,y)
//utilizzando il colore color
void colonnaColore(int x, int y, int lung, char car, int color) {
    int current = getTextColor();
    setTextColor(color);
    gotoxy(x, y);
    for(int k = 0; k < lung; k++) {
        printf("%c", car);
    }
    setTextColor(current);
}
//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car
void rettangoloPieno(int x, int y, int b, int h, char car){
   for (int k = 0 ; k < h; k++){
    riga(x, y, b, car);
    y = y + 1;
}
}

//disegna un rettangolo pieno di base b e altezza h
//con angolo alto sx nella posizione (x,y)
//usando il carattere car e utilizzando il colore color
void rettangoloPienoColore(int x, int y, int b, int h, char car, int color){
for (int k = 0 ; k < h; k++){
    rigaColore(x, y, b, car, color);
    y = y + 1;
}
}
