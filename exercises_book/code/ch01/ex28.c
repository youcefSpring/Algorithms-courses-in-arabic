#include <stdio.h>

int main(void) {
    double slope, intercept, x1, x2, y1, y2;
    scanf("%lf %lf", &slope, &intercept);     // معاملا النموذج
    scanf("%lf %lf", &x1, &x2);   // ميزانيتان
    y1 = slope * x1 + intercept;              // التنبؤ الأول
    y2 = slope * x2 + intercept;              // التنبؤ الثاني
    printf("Prediction 1 = %.1f\n", y1);
    printf("Prediction 2 = %.1f\n", y2);
    printf("Gain = %.1f\n", y2 - y1);   // = slope × (x2 - x1)
    return 0;
}
