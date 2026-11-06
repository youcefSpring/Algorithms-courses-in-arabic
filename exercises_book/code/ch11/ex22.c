#include <stdio.h>

double mySqrt(double value) {
    double guess = value > 1 ? value : 1;
    int iter;
    if (value <= 0) return 0;
    for (iter = 0; iter < 60; iter++) guess = (guess + value / guess) / 2;
    return guess;
}

int main(void) {
    FILE *file = fopen("metrics.txt", "w");
    char header[100], names[3][10] = {"visits", "orders", "revenue"};
    double row[3], sum[3] = {0}, sumSq[3] = {0}, low[3], high[3], mean;
    int col, count = 0;
    fprintf(file, "visits orders revenue\n1200 36 182000\n1350 41 205000\n980 25 131000\n");
    fprintf(file, "1610 52 268000\n1420 39 199500\n1105 30 150500\n");
    fclose(file);
    file = fopen("metrics.txt", "r");
    fgets(header, 100, file);                         // سطر العناوين
    while (fscanf(file, "%lf %lf %lf", &row[0], &row[1], &row[2]) == 3) {
        for (col = 0; col < 3; col++) {
            sum[col] += row[col];
            sumSq[col] += row[col] * row[col];
            if (count == 0 || row[col] < low[col]) low[col] = row[col];
            if (count == 0 || row[col] > high[col]) high[col] = row[col];
        }
        count++;
    }
    fclose(file);
    for (col = 0; col < 3; col++) {
        mean = sum[col] / count;
        printf("%-8s mean %10.2f  std %9.2f  min %8.0f  max %8.0f\n", names[col], mean,
               mySqrt(sumSq[col] / count - mean * mean), low[col], high[col]);
    }
    return 0;
}
