#include <stdio.h>

typedef struct {
    char nom[30];
    int age;
} Personne;

static void exercice_3(void) {
    printf("--- R3 : structures ---\n");

    Personne p;
    snprintf(p.nom, sizeof(p.nom), "%s", "Camille");
    p.age = 23;

    Personne *ptr = &p; /* l'adresse de p */
    printf("  p.nom = %s\n", p.nom);
    printf("  ptr->nom = %s\n", ptr->nom);
    printf("  (*ptr).age = %d\n", (*ptr).age);
    printf("  sizeof(Personne) = %zu octets\n", sizeof(Personne));
}

int main(void) {
    exercice_3();
    return 0;
}
