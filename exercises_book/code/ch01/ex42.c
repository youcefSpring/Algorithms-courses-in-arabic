#include <stdio.h>

int main(void) {
    double rating1, rating2, rating3, mean, variance, root;
    scanf("%lf %lf %lf", &rating1, &rating2, &rating3);
    mean = (rating1 + rating2 + rating3) / 3;                      // المتوسط
    variance = ((rating1 - mean) * (rating1 - mean) + (rating2 - mean) * (rating2 - mean)
       + (rating3 - mean) * (rating3 - mean)) / 3;              // التباين
    root = variance + 1;                                // تقدير أولي أكبر من الجذر
    // كل تكرار يضاعف تقريبًا عدد الأرقام الصحيحة
    root = (root + variance / root) / 2;
    root = (root + variance / root) / 2;
    root = (root + variance / root) / 2;
    root = (root + variance / root) / 2;
    root = (root + variance / root) / 2;
    root = (root + variance / root) / 2;
    printf("Variance = %.6f\n", variance);
    printf("Std dev  = %.6f\n", root);
    printf("Check r*r = %.6f\n", root * root);      // يجب أن يساوي التباين
    return 0;
}
