#include <stdio.h>

#define NB 3

int main(void) {
    double matrix[NB][NB] = {{2, 1, 1}, {1, 3, 2}, {1, 0, 0}};
    double work[NB][2 * NB], factor, tmp, check;
    int pivot, row, col, swapRow, inner;
    for (row = 0; row < NB; row++)
        for (col = 0; col < 2 * NB; col++)
            work[row][col] = (col < NB) ? matrix[row][col] : (col - NB == row);  // [A | I]
    for (pivot = 0; pivot < NB; pivot++) {
        if (work[pivot][pivot] == 0) {            // محور معدوم: نبحث عن سطر آخر
            for (swapRow = pivot + 1; swapRow < NB && work[swapRow][pivot] == 0; swapRow++)
                ;
            if (swapRow == NB) { printf("Matrix is not invertible\n"); return 0; }
            for (col = 0; col < 2 * NB; col++) {
                tmp = work[pivot][col]; work[pivot][col] = work[swapRow][col]; work[swapRow][col] = tmp;
            }
        }
        factor = work[pivot][pivot];
        for (col = 0; col < 2 * NB; col++)
            work[pivot][col] /= factor;           // المحور يصبح 1
        for (row = 0; row < NB; row++)
            if (row != pivot) {                   // نصفر العمود في باقي الأسطر
                factor = work[row][pivot];
                for (col = 0; col < 2 * NB; col++)
                    work[row][col] -= factor * work[pivot][col];
            }
    }
    printf("Inverse:\n");
    for (row = 0; row < NB; row++) {
        for (col = NB; col < 2 * NB; col++)
            printf(" %7.3f", work[row][col]);
        printf("\n");
    }
    printf("Check A x inv (diagonal):");
    for (row = 0; row < NB; row++) {
        check = 0;
        for (inner = 0; inner < NB; inner++)
            check += matrix[row][inner] * work[inner][NB + row];
        printf(" %.3f", check);
    }
    printf("\n");
    return 0;
}
