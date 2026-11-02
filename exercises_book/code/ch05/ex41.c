#include <stdio.h>

#define NB 4

int main(void) {
    double aug[NB][NB + 1] = {{ 2,  1, -1,  3,  18},     // المصفوفة الموسعة [A | b]
                              { 4,  1,  2, -1,  14},
                              {-2,  5,  1,  1,  20},
                              { 1, -1,  3,  2,  21}};
    double solution[NB], factor, tmp, bestVal, value, sum;
    int pivotCol, row, col, best;
    for (pivotCol = 0; pivotCol < NB; pivotCol++) {
        best = pivotCol;                          // الارتكاز الجزئي
        bestVal = aug[pivotCol][pivotCol] < 0 ? -aug[pivotCol][pivotCol] : aug[pivotCol][pivotCol];
        for (row = pivotCol + 1; row < NB; row++) {
            value = aug[row][pivotCol] < 0 ? -aug[row][pivotCol] : aug[row][pivotCol];
            if (value > bestVal) { bestVal = value; best = row; }
        }
        for (col = 0; col <= NB; col++) {         // تبديل السطرين
            tmp = aug[pivotCol][col]; aug[pivotCol][col] = aug[best][col]; aug[best][col] = tmp;
        }
        for (row = pivotCol + 1; row < NB; row++) {   // الحذف تحت المحور
            factor = aug[row][pivotCol] / aug[pivotCol][pivotCol];
            for (col = pivotCol; col <= NB; col++)
                aug[row][col] -= factor * aug[pivotCol][col];
        }
    }
    for (row = NB - 1; row >= 0; row--) {         // التعويض التراجعي
        sum = aug[row][NB];
        for (col = row + 1; col < NB; col++)
            sum -= aug[row][col] * solution[col];
        solution[row] = sum / aug[row][row];
    }
    for (row = 0; row < NB; row++)
        printf("x%d = %.4f\n", row + 1, solution[row]);
    return 0;
}
