#include <stdio.h>

int main(void) {
    int A[2][3] = {{1, 2, 3}, {4, 5, 6}};
    int T[3][2], i, j;
    for (i = 0; i < 2; i++)
        for (j = 0; j < 3; j++)
            T[j][i] = A[i][j];
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) printf("%4d", T[i][j]);
        printf("\n");
    }
    return 0;
}
