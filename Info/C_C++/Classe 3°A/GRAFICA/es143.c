/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>  //contiene la funzione random
#include <stdlib.h>  //gestisce intervalli di tempo
#include <time.h>
#include "utility.h"
#define WIDTH 200
#define HEIGHT 80
main(){
    int x, y, numcol, colore;

    cursor_hide();
    unsigned short coloreAttuale;
    coloreAttuale = getTextColor();
    setConsoleDimensions(WIDTH, HEIGHT);
    x=0;
    y=0;
    for (numcol = 0; numcol < 256; numcol++){
            gotoxy(x, y);
            setTextColor(coloreAttuale);
            printf("%d = ", numcol);
            setTextColor(numcol);
            printf("*");
            y++;
            if(y == 16){
                 y = 0;
                 x = x + 7;
            }
            setTextColor(coloreAttuale);
    }

}
