#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rows, cols, row, col;
    double **sales, sum;
    scanf("%d %d", &rows, &cols);
    sales = malloc(rows * sizeof(double *));          // جدول مؤشرات الأسطر
    for (row = 0; row < rows; row++)
        sales[row] = malloc(cols * sizeof(double));   // كل سطر على حدة
    for (row = 0; row < rows; row++)
        for (col = 0; col < cols; col++) scanf("%lf", &sales[row][col]);
    for (row = 0; row < rows; row++) {
        for (sum = 0, col = 0; col < cols; col++) sum += sales[row][col];
        printf("Branch %d: %.0f\n", row + 1, sum);
    }
    printf("Per day:");
    for (col = 0; col < cols; col++) {
        for (sum = 0, row = 0; row < rows; row++) sum += sales[row][col];
        printf(" %.0f", sum);
    }
    printf("\n");
    for (row = 0; row < rows; row++) free(sales[row]);  // الأسطر أولًا
    free(sales);
    return 0;
}
