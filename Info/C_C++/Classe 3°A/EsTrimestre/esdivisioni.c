/*
author: Prandi Alessandro
date:30/11/2022
es. divisioni
testo
*/

#include <stdio.h>
#include <stdlib.h>

main() {
    int x = 3;
    int y = 2;
    float z;

//assegnamo come reale la variabile mettendo (float) davanti
    z = (float) x / y;
    printf("%.2f \n", z);

    z=3;
    z= z/y;
    printf("%.2f\n", z);

    z = x / (float) y;
    printf("%.2f \n", z);

}
