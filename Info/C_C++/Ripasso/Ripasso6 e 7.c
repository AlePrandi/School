/*
author: Prandi Alessandro
date:
es.
testo
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool eTriang(int n1,int n2,int n3) {
    bool triangolo = false;
    if(n1 > 0 && n2 > 0 && n3 > 0) {
        if(n1 < n2 + n3) {
            if(n2 < n1 + n3) {
                if(n3 < n1 + n2) {
                    triangolo = true;
                }
            }
        }
    }
    return triangolo;
}

bool isIsocele(int n1,int n2,int n3) {
    bool isoscele = false;
    if(n1 == n2 || n1 == n3 || n2 == n3) {
        isoscele = true;
    }
    return isoscele;
}

int main() {
    int l1,l2,l3;
    do {
        printf("Inserisci tre lati: ");
        scanf("%d %d %d", &l1,&l2,&l3);
    } while(l1 < 0 || l2 < 0 || l3 < 0);
    if(eTriang(l1,l2,l3) == true) {
        if(isIsocele(l1,l2,l3) == true) {
            printf("e' un triangolo isoscele");
        } else {
            printf("e' un triangolo");
        }
    } else {
        printf("non e' un triangolo");
    }
    return 0;
}
