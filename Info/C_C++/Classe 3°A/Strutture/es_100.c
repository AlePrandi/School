/*
author: Prandi Alessandro
date: 09/05/2023
es.
testo:
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define LUNG 30

typedef struct{
    int giorno;
    int mese;
    int anno;
}Data;

typedef struct{
    char nome[LUNG];
    char cognome[LUNG];
    Data nascita;
}Persona;

void visDati(Persona s){
    printf("la persona %s %s ", s.nome, s.cognome);
    printf("e nata il %d/%d/%d", s.nascita.giorno, s.nascita.mese, s.nascita.anno);
}

int main () {
    Persona p1;

    printf("Inserisci il tuo nome: ");
    gets(p1.nome);
    printf("Inserisci il tuo cognome: ");
    gets(p1.cognome);
    printf("Inserisci la tua data di nascita (scrivi come questo esempio: xx/xx/xxxx): ");
    scanf("%d/%d/%d", &p1.nascita.giorno, &p1.nascita.mese, &p1.nascita.anno);
    visDati(p1);

    return 0;
}
