#include <stdio.h>
#define L 3
#define C 4

int main(void) {
    int M[L][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12}};
    int i, j, s;
    for (i = 0; i < L; i++) {
        s = 0;
        for (j = 0; j < C; j++) s = s + M[i][j];
        printf("Row %d: %d\n", i, s);
    }
    return 0;
}
