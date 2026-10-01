#include <stdio.h>
#include <stdlib.h>

static void exercice_5(void) {
    printf("--- R5 : memoire dynamique ---\n");

    int n = 5;
    int *tab = malloc(n * sizeof(int));
    if (tab == NULL) { perror("malloc"); exit(EXIT_FAILURE); }

    for (int i = 0; i < n; i++) tab[i] = i * i;
    printf("  tab = ");
    for (int i = 0; i < n; i++) printf("%d ", tab[i]);
    printf("\n");

    /* agrandir : toujours par une variable temporaire */
    int *tmp = realloc(tab, 10 * sizeof(int));
    if (tmp == NULL) { free(tab); perror("realloc"); exit(EXIT_FAILURE); }
    tab = tmp;

    for (int i = n; i < 10; i++) tab[i] = i * i;
    printf("  apres realloc a 10 : ");
    for (int i = 0; i < 10; i++) printf("%d ", tab[i]);
    printf("\n");

    free(tab);   /* rendre le bloc */
    tab = NULL;  /* reflexe : evite une double liberation */
    printf("  libere, pointeur remis a NULL\n");

    /* Question C : second free sur un pointeur NULL */
    free(tab);
    printf("  second free(tab) avec tab == NULL : aucun effet\n");
}

int main(void) {
    exercice_5();
    return 0;
}
