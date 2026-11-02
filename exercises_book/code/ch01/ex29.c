#include <stdio.h>

int main(void) {
    double x1, y1, x2, y2, slope, intercept, sales;
    scanf("%lf %lf %lf %lf", &x1, &y1, &x2, &y2);
    slope = (y2 - y1) / (x2 - x1);    // الميل: تغير sales لكل وحدة من x
    intercept = y1 - slope * x1;              // من y1 = slope*x1 + intercept
    sales = slope * 120 + intercept;              // التنبؤ عند السعر 120
    printf("Slope a = %.2f\n", slope);
    printf("Intercept b = %.2f\n", intercept);
    printf("Sales at 120 DA = %.0f\n", sales);
    return 0;
}
