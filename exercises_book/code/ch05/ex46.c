#include <stdio.h>

#define NB 8
#define NB_COEF 3

int main(void) {
    double x1[NB] = {1, 2, 3, 4, 5, 6, 7, 8};             // الإعلان
    double x2[NB] = {0, 1, 0, 2, 1, 3, 2, 3};             // التخفيضات
    double sales[NB]  = {14, 22, 21, 35, 33, 47, 44, 52};     // المبيعات
    double design[NB][NB_COEF], aug[NB_COEF][NB_COEF + 1], beta[NB_COEF];
    double factor, sum, mean = 0, ssRes = 0, ssTot = 0, predicted;
    int row, colA, colB, pivot;
    for (row = 0; row < NB; row++) {
        design[row][0] = 1; design[row][1] = x1[row]; design[row][2] = x2[row];
        mean += sales[row] / NB;
    }
    for (colA = 0; colA < NB_COEF; colA++) {      // المعادلات الطبيعية
        for (colB = 0; colB < NB_COEF; colB++) {
            aug[colA][colB] = 0;
            for (row = 0; row < NB; row++)
                aug[colA][colB] += design[row][colA] * design[row][colB];
        }
        aug[colA][NB_COEF] = 0;
        for (row = 0; row < NB; row++)
            aug[colA][NB_COEF] += design[row][colA] * sales[row];
    }
    for (pivot = 0; pivot < NB_COEF; pivot++)     // الحذف (XtX موجبة: لا ارتكاز)
        for (row = pivot + 1; row < NB_COEF; row++) {
            factor = aug[row][pivot] / aug[pivot][pivot];
            for (colB = pivot; colB <= NB_COEF; colB++)
                aug[row][colB] -= factor * aug[pivot][colB];
        }
    for (row = NB_COEF - 1; row >= 0; row--) {    // التعويض التراجعي
        sum = aug[row][NB_COEF];
        for (colB = row + 1; colB < NB_COEF; colB++)
            sum -= aug[row][colB] * beta[colB];
        beta[row] = sum / aug[row][row];
    }
    for (row = 0; row < NB; row++) {
        predicted = beta[0] + beta[1] * x1[row] + beta[2] * x2[row];
        ssRes += (sales[row] - predicted) * (sales[row] - predicted);
        ssTot += (sales[row] - mean) * (sales[row] - mean);
    }
    printf("sales = %.3f + %.3f*ads + %.3f*promos\n", beta[0], beta[1], beta[2]);
    printf("R^2 = %.4f\n", 1 - ssRes / ssTot);
    return 0;
}
