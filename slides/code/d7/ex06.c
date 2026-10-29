#include <stdio.h>
#include <stdlib.h>

int dice(void) {
    return rand() % 6 + 1;
}

int main(void) {
    int i;
    srand(2026);     /* fixed seed: same game */
    for (i = 1; i <= 5; i++)
        printf("Roll %d: %d\n", i, dice());
    return 0;
}
