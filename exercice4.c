#include <stdio.h>
#include <stdbool.h>

static void doubler_copie(int v) { v = v * 2; }
static void doubler_vrai(int *v) { *v = *v * 2; }

/* Question C : un tableau passe en parametre est-il copie ? */
static void mettre_a_zero(int t[], int n) {
    printf("  adresse recue par la fonction : %p\n", (void *)t);
    for (int i = 0; i < n; i++) t[i] = 0;
}

static void exercice_4(void) {
    printf("--- R4 : pointeurs ---\n");

    int x = 21;
    doubler_copie(x);
    printf("  apres doubler_copie(x) : x = %d\n", x);
    doubler_vrai(&x);
    printf("  apres doubler_vrai(&x) : x = %d\n", x);

    int *p = NULL;
    printf("  p == NULL : %s\n", (p == NULL) ? "true" : "false");

    int t[3] = { 1, 2, 3 };
    printf("  adresse du tableau dans l'appelant : %p\n", (void *)t);
    mettre_a_zero(t, 3);
    printf("  t apres mettre_a_zero : %d %d %d\n", t[0], t[1], t[2]);
}

int main(void) {
    exercice_4();
    return 0;
}
