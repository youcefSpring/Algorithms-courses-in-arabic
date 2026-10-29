#include <stdio.h>

int main(void) {
    int i, j, n = 4, matches = 0;
    for (i = 1; i <= n; i++)
        for (j = i + 1; j <= n; j++) {
            printf("Team %d vs Team %d\n", i, j);
            matches++;
        }
    printf("Matches = %d\n", matches);
    return 0;
}
