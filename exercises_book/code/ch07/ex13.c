#include <stdio.h>

double sumArray(double values[], int size) {
    double total = 0;
    int idx;
    for (idx = 0; idx < size; idx++)
        total += values[idx];
    return total;
}

double meanArray(double values[], int size) {
    return sumArray(values, size) / size;    // إعادة استعمال الدالة الأولى
}

int main(void) {
    double branchA[5] = {1200, 980, 1430, 1100, 1290};
    double branchB[3] = {640, 710, 690};
    printf("Branch A: total %.0f, mean %.2f\n", sumArray(branchA, 5), meanArray(branchA, 5));
    printf("Branch B: total %.0f, mean %.2f\n", sumArray(branchB, 3), meanArray(branchB, 3));
    return 0;
}
