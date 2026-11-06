#include <stdio.h>

int movingAverage(double values[], int size, int window, double result[]) {
    double sum = 0;
    int idx;
    for (idx = 0; idx < window; idx++) sum += values[idx];
    result[0] = sum / window;
    for (idx = window; idx < size; idx++) {
        sum += values[idx] - values[idx - window];   // النافذة تنزلق بخانة
        result[idx - window + 1] = sum / window;
    }
    return size - window + 1;
}

void printSeries(char label[], double values[], int size) {
    int idx;
    printf("%s", label);
    for (idx = 0; idx < size; idx++) printf(" %5.1f", values[idx]);
    printf("\n");
}

int main(void) {
    double sales[10] = {50, 72, 41, 66, 90, 58, 63, 95, 70, 81};
    double smooth[10];
    int count;
    printSeries("raw  :", sales, 10);
    count = movingAverage(sales, 10, 3, smooth);
    printSeries("MA(3):", smooth, count);
    count = movingAverage(sales, 10, 5, smooth);
    printSeries("MA(5):", smooth, count);
    return 0;
}
