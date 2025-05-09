/*
author: Prandi Alessandro
date: 4/12/2022
es. rand3
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define LIM_MIN -50
#define LIM_MAX 50

int main()
{
    srand(time(NULL));
    int n= LIM_MIN + rand()% (LIM_MAX-LIM_MIN+1);
    int pos=0;
    int neg=0;
    int min;
    while(n!=0){
        if(pos==0 && neg==0){
            min=n;
        }
        else
        if (n<min)
        min = n;
        if(n>0){
            pos=pos+1;
        }
        else if(n<0){
            neg=neg+1;
        }
        n= LIM_MIN + rand()% (LIM_MAX-LIM_MIN+1);
        printf("numero casuale: %d\n",n);
    }
    printf("I numeri negativi sono: %d\n", neg);
    printf("I numeri positivi sono: %d\n", pos);
    printf("Il minore e: %d\n", min);

}
