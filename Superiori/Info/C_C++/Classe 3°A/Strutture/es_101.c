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
#define DIM 5

int chiediDim(int dim_max, char msg[]) {
    int dim;
    printf("%s", msg);
    do {
        printf(" tra [0 e %d]: ", dim_max);
        scanf("%d", &dim);
    } while (dim < 0 || dim > dim_max);
    return dim;
}
typedef struct {
    int giorno;
    int mese;
    int anno;
} Data;
typedef struct {
    Data voto;
    float voto_preso;
} Voto;
typedef struct {
    char nome[LUNG];
    char cognome[LUNG];
    Data nascita;
    Voto voti[2];
} Persona;

void CaricaDati(Persona *s) {
    printf("Inserisci il tuo nome: ");
    gets(s->nome);
    printf("Inserisci il tuo cognome: ");
    gets(s->cognome);
    printf("Inserisci la tua data di nascita (scrivi come questo esempio: xx/xx/xxxx): ");
    scanf("%d/%d/%d", &s->nascita.giorno, &s->nascita.mese, &s->nascita.anno);
    for (int k = 0; k < 2; k++) {
        printf("Inserisci la data del voto: ");
        scanf("%d/%d/%d", &s->voti[k].voto.giorno, &s->voti[k].voto.mese, &s->voti[k].voto.anno);
        printf("Inserisci il voto: ");
        scanf("%f", &s->voti[k].voto_preso);
    }
}
void LeggiClasse(Persona tab[], int n) {
    for (int k = 0; k < n; k++) {
        CaricaDati(&tab[k]);
    }
}
void VisDati(Persona *s) {
    printf("la persona %s %s ", s->nome, s->cognome);
    printf("nata il %d/%d/%d\n", s->nascita.giorno, s->nascita.mese, s->nascita.anno);
    for (int k = 0; k < 2; k++) {
        printf("il giorno %d/%d/%d ", s->voti[k].voto.giorno, s->voti[k].voto.mese, s->voti[k].voto.anno);
        printf("ha preso %.2f ", s->voti[k].voto_preso);
    }
}
void VisClasse(Persona tab[], int n) {
    for (int k = 0; k < n; k++) {
        VisDati(&tab[k]);
    }
}
int main () {
    Persona Classe[DIM];
    int n = chiediDim(DIM,"inserisci il numero di alunni");
    Persona p1;
    LeggiClasse(Classe, n);
    VisClasse(Classe, n);
    return 0;
}
