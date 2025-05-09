/*
author: Prandi Alessandro
date: 11/01/2023
es. neve
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include "GraficaPrandi.h"

#define FIOCCO '*'
#define BIANCO 15
#define NERO 0
#define YTERRENO 23
#define PAUSA 200
#define WIDTH 80
#define HEIGHT 30

void inizializzaFiocco(int *x, int *y){
 *y = rand() % (HEIGHT / 3);
 *x = rand() % (WIDTH - 2) + 1;
}

void fiocchi(int *x, int *y){
*y = *y + 1;
*x = *x + rand() % 2 -1;
if (*x <= 0 || *x >= WIDTH ){
inizializzaFiocco(x , y);
}
if (*y == YTERRENO){
    inizializzaFiocco(x , y);//&*x
}
puntoColore(*x, *y , FIOCCO, BIANCO);
}

void cancellaFiocchi(int x,int y){
gotoxy(x, y);
setTextColor(NERO);
printf(" ");
}

int main(){
 cursor_hide();
 setConsoleDimensions(WIDTH, HEIGHT);
 srand(time(NULL));

 int x1,x2,x3,x4,x5;
 int y1,y2,y3,y4,y5;
    inizializzaFiocco(&x1, &y1);
    inizializzaFiocco(&x2, &y2);
    inizializzaFiocco(&x3, &y3);
    inizializzaFiocco(&x4, &y4);
    inizializzaFiocco(&x5, &y5);

 while(1){
    setTextColor(0);
    clrscr();// clrscr(); non mettere altrimente flasha
    cancellaFiocchi(x1,y1);
    fiocchi(&x1, &y1);
    cancellaFiocchi(x2,y2);
    fiocchi(&x2, &y2);
    cancellaFiocchi(x3,y3);
    fiocchi(&x3, &y3);
    cancellaFiocchi(x4,y4);
    fiocchi(&x4, &y4);
    cancellaFiocchi(x5,y5);
    fiocchi(&x5, &y5);
    delay(PAUSA);
 }
 return 0;
}
