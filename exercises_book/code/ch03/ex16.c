#include <stdio.h>

int main(void) {
    int packA, packB, rest, a0, b0;
    scanf("%d %d", &packA, &packB);
    a0 = packA; b0 = packB;               // نحفظ القيم الأصلية للعرض
    while (packB != 0) {
        rest = packA % packB;                // pgcd(packA, packB) = pgcd(packB, packA % packB)
        packA = packB;
        packB = rest;
    }
    printf("GCD(%d, %d) = %d\n", a0, b0, packA);
    printf("Shelves of %d units: %d + %d\n", packA, a0 / packA, b0 / packA);
    return 0;
}
