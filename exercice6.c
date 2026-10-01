#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Maillon {
    int valeur;
    struct Maillon *suivant; /* l'adresse du maillon suivant */
} Maillon;

static Maillon *inserer_en_tete(Maillon *tete, int valeur) {
    Maillon *m = malloc(sizeof(Maillon));
    if (m == NULL) { perror("malloc"); exit(EXIT_FAILURE); }
    m->valeur = valeur;
    m->suivant = tete; /* 1. il pointe l'ancienne tete */
    return m;          /* 2. il devient la nouvelle tete */
}

static int longueur(const Maillon *tete) {
    int n = 0;
    for (const Maillon *m = tete; m != NULL; m = m->suivant) n++;
    return n;
}

static bool contient(const Maillon *tete, int valeur) {
    for (const Maillon *m = tete; m != NULL; m = m->suivant)
        if (m->valeur == valeur) return true;
    return false;
}

static void afficher(const Maillon *tete) {
    for (const Maillon *m = tete; m != NULL; m = m->suivant)
        printf("%d -> ", m->valeur);
    printf("NULL\n");
}

static void liberer(Maillon *tete) {
    Maillon *m = tete;
    while (m != NULL) {
        Maillon *suiv = m->suivant; /* sauvegarder AVANT de liberer */
        free(m);
        m = suiv;
    }
}

static void exercice_6(void) {
    printf("--- R6 : liste chainee ---\n");

    Maillon *liste = NULL; /* une liste vide */
    for (int i = 1; i <= 5; i++) liste = inserer_en_tete(liste, i * 10);

    printf("  liste : ");
    afficher(liste);
    printf("  longueur : %d\n", longueur(liste));
    printf("  contient 30 : %s\n", contient(liste, 30) ? "oui" : "non");
    printf("  contient 99 : %s\n", contient(liste, 99) ? "oui" : "non");
    printf("  liste vide, contient 30 : %s\n", contient(NULL, 30) ? "oui" : "non");

    liberer(liste);
    printf("  liberee\n");
}

int main(void) {
    exercice_6();
    return 0;
}
