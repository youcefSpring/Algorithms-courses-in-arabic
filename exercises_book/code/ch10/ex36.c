#include <stdio.h>
#include <stdlib.h>

double **newMatrix(int rows, int cols) {
    double **matrix = malloc(rows * sizeof(double *));
    int row, col;
    for (row = 0; row < rows; row++) {
        matrix[row] = malloc(cols * sizeof(double));
        for (col = 0; col < cols; col++) matrix[row][col] = 0;
    }
    return matrix;
}

void freeMatrix(double **matrix, int rows) {
    int row;
    for (row = 0; row < rows; row++) free(matrix[row]);
    free(matrix);
}

int main(void) {
    double qtyData[3][4] = {{10, 5, 0, 8}, {4, 12, 6, 2}, {7, 0, 9, 5}};
    double costData[4][2] = {{1200, 50}, {3200, 120}, {899, 30}, {4100, 150}};
    double **qty = newMatrix(3, 4), **cost = newMatrix(4, 2), **result = newMatrix(3, 2);
    int row, col, mid;
    for (row = 0; row < 3; row++) for (col = 0; col < 4; col++) qty[row][col] = qtyData[row][col];
    for (row = 0; row < 4; row++) for (col = 0; col < 2; col++) cost[row][col] = costData[row][col];
    for (row = 0; row < 3; row++)
        for (col = 0; col < 2; col++)
            for (mid = 0; mid < 4; mid++)
                result[row][col] += qty[row][mid] * cost[mid][col];   // سطر × عمود
    for (row = 0; row < 3; row++)
        printf("Branch %d: purchase %8.0f DA, transport %6.0f DA\n", row + 1, result[row][0], result[row][1]);
    freeMatrix(qty, 3);
    freeMatrix(cost, 4);
    freeMatrix(result, 3);
    return 0;
}
