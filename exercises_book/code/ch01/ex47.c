#include <stdio.h>

int main(void) {
    double alpha, p1, p2, p3, p4, ema;
    scanf("%lf", &alpha);                 // معامل التنعيم بين 0 و1
    scanf("%lf %lf %lf %lf", &p1, &p2, &p3, &p4);
    ema = p1;                               // البداية: أول سعر
    printf("t1: %.2f\n", ema);
    ema = alpha * p2 + (1 - alpha) * ema;     // وزن alpha للسعر الجديد
    printf("t2: %.2f\n", ema);
    ema = alpha * p3 + (1 - alpha) * ema;
    printf("t3: %.2f\n", ema);
    ema = alpha * p4 + (1 - alpha) * ema;
    printf("t4: %.2f\n", ema);
    return 0;
}
