#include <stdio.h>
#include <string.h>

static void exercice_2(void) {
    printf("--- R2 : tableaux et chaines ---\n");

    char mot[20];
    snprintf(mot, sizeof(mot), "%s", "bonjour");
    printf("  mot = %s\n", mot);
    printf("  strlen(mot) = %lu\n", (unsigned long)strlen(mot));
    printf("  sizeof(mot) = %lu\n", (unsigned long)sizeof(mot));

    const char *a = "chat";
    char b[10];
    snprintf(b, sizeof(b), "%s", "chat");
    printf("  a == b = %s\n", ((const char *)a == b) ? "true" : "false");
    printf("  strcmp(a,b)==0 = %s\n", (strcmp(a, b) == 0) ? "true" : "false");
}

int main(void) {
    exercice_2();
    return 0;
}