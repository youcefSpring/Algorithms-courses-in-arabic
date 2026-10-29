#include <stdio.h>
#define R 4
#define C 6
int main(void) {
    int seat[R][C] = {{1, 1, 0, 0, 1, 1},
                      {0, 1, 1, 1, 1, 0},
                      {0, 0, 0, 1, 0, 0},
                      {1, 1, 1, 1, 1, 1}};
    int i, j, f;
    for (i = 0; i < R; i++) {
        f = 0;
        for (j = 0; j < C; j++)
            if (seat[i][j] == 0) f++;
        printf("Row %d: %d free\n", i + 1, f);
    }
    return 0;
}
