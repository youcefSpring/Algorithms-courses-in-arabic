#include <stdio.h>

int main(void) {
    int rev, nbOrders, quotient;
    double avg;
    scanf("%d %d", &rev, &nbOrders);
    quotient = rev / nbOrders;                  // قسمة صحيحة: الجزء العشري يضيع
    avg = (double)rev / nbOrders;        // قسمة حقيقية
    printf("Integer division = %d\n", quotient);
    printf("Real division    = %.4f\n", avg);
    printf("Lost part        = %.4f\n", avg - quotient);
    return 0;
}
