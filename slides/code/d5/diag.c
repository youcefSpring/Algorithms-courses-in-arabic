#include <stdio.h>
#define N 3

int main(void) {
    int M[N][N] = {{2, 0, 1}, {4, 5, 3}, {7, 8, 9}};
    int i, trace = 0;
    for (i = 0; i < N; i++) {
        trace = trace + M[i][i];
    }
    printf("Trace = %d\n", trace);
    return 0;
}
