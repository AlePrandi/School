/*
author: Prandi Alessandro
date: 11/12/2022
es. 141
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include "utility.h"

int main () {
    int width = 50;
    int height = 10;
    setConsoleDimensions(width, height);
    cursor_hide();
    while(1){
     gotoxy(width/2 - 5.5, height/2);
    setTextColor(4);
    printf("Hello world");
    }

return 0;
}

