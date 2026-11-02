#include <stdio.h>

int main(void) {
    double day1, day2, day3, day4, mean, variance;
    scanf("%lf %lf %lf %lf", &day1, &day2, &day3, &day4);
    mean = (day1 + day2 + day3 + day4) / 4;          // المتوسط
    // التباين: متوسط مربعات الانحرافات
    variance = ((day1 - mean) * (day1 - mean) + (day2 - mean) * (day2 - mean)
       + (day3 - mean) * (day3 - mean) + (day4 - mean) * (day4 - mean)) / 4;
    printf("Mean = %.2f\n", mean);
    printf("Variance = %.2f\n", variance);
    return 0;
}
