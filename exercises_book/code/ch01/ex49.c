#include <stdio.h>

int main(void) {
    double P1, Q1, P2, Q2, dq, dp, elasticity;
    scanf("%lf %lf %lf %lf", &P1, &Q1, &P2, &Q2);
    dq = (Q2 - Q1) / ((Q1 + Q2) / 2);     // التغير النسبي للكمية
    dp = (P2 - P1) / ((P1 + P2) / 2);     // التغير النسبي للسعر
    elasticity = dq / dp;                          // المرونة
    printf("Elasticity = %.3f\n", elasticity);
    printf("Revenue before = %.0f DA\n", P1 * Q1);
    printf("Revenue after  = %.0f DA\n", P2 * Q2);
    return 0;
}
