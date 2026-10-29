#include <stdio.h>
#define L 3
#define C 4

int main(void) {
    int M[L][C] = {{1, 2, 3, 4},
                   {5, 6, 7, 8},
                   {9, 10, 11, 12}};
    int i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            printf("%4d", M[i][j]);
        }
        printf("\n");
    }
    return 0;
}
