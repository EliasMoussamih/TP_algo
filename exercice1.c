#include <stdio.h>
#include <limits.h>

static void exercice_1(void) {
    printf("--- R1 : entiers ---\n");

    int a = 2147483647;         /* le plus grand int sur 32 bits */
    unsigned int b = UINT_MAX;  /* le plus grand unsigned int */
    printf("  int max = %d\n", a);
    printf("  int max + 1 = %d\n", a + 1);   /* debordement signe : comportement indefini */
    printf("  uint max = %u\n", b);
    printf("  uint max + 1 = %u\n", b + 1);  /* arithmetique modulo 2^32 : bien defini */

    int n = -7;
    printf("  -7 %% 3 = %d\n", n % 3);
}

int main(void) {
    exercice_1();
    return 0;
}
