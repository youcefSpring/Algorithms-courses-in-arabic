#include <stdio.h>

int main(void) {
    int i, j;
    for (i = 1; i <= 3; i++) {
        for (j = 1; j <= 4; j++) {
            printf("%4d", i * j);
        }
        printf("\n");
    }
    return 0;
}
