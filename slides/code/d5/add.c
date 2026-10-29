#include <stdio.h>
#define L 2
#define C 3

int main(void) {
    int A[L][C] = {{1, 2, 3}, {4, 5, 6}};
    int B[L][C] = {{6, 5, 4}, {3, 2, 1}};
    int S[L][C], i, j;
    for (i = 0; i < L; i++) {
        for (j = 0; j < C; j++) {
            S[i][j] = A[i][j] + B[i][j];
            printf("%4d", S[i][j]);
        }
        printf("\n");
    }
    return 0;
}
