#include <stdio.h>

int sum(int T[], int n) {
    int i, s = 0;
    for (i = 0; i < n; i++)
        s += T[i];
    return s;
}

int main(void) {
    int A[5] = {4, 8, 15, 16, 23};
    printf("Sum = %d\n", sum(A, 5));
    return 0;
}
