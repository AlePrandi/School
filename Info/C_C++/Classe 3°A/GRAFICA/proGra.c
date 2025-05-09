/*
author: Prandi Alessandro
date: 12/12/2022
es. 000
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"
main() {
    unsigned short colAtt;
    int vel = 100;

    cursor_hide();

    setTextColor(36);
    while(1) {
        setConsoleDimensions(80, 30);
        gotoxy(3, 5);
        printf("ciao");
        delay(vel);
        setTextColor(colAtt);
        clrscr();
        delay(vel);
    }
}
