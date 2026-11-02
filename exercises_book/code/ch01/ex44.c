#include <stdio.h>

int main(void) {
    double x1, y1, x2, y2, x3, y3, Sx, Sy, Sxy, Sxx, slope, intercept;
    const int nbPoints = 3;                      // عدد النقاط
    scanf("%lf %lf %lf %lf %lf %lf", &x1, &y1, &x2, &y2, &x3, &y3);
    Sx = x1 + x2 + x3;                    // مجموع x
    Sy = y1 + y2 + y3;                    // مجموع y
    Sxy = x1 * y1 + x2 * y2 + x3 * y3;    // مجموع الجداءات
    Sxx = x1 * x1 + x2 * x2 + x3 * x3;    // مجموع المربعات
    slope = (nbPoints * Sxy - Sx * Sy) / (nbPoints * Sxx - Sx * Sx);   // الميل
    intercept = (Sy - slope * Sx) / nbPoints;                // الجزء المقطوع
    printf("y = %.4f x + %.4f\n", slope, intercept);
    printf("Prediction at x = 3: %.4f\n", slope * 3 + intercept);
    return 0;
}
