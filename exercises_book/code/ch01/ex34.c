#include <stdio.h>

int main(void) {
    int amount, pts, missing, vouchers;
    scanf("%d", &amount);
    pts = amount / 100;               // نقطة لكل 100 دج كاملة
    missing = 100 - amount % 100;     // ما ينقص للوصول إلى المئة التالية
    vouchers = pts / 50;              // قسيمة لكل 50 نقطة
    printf("Points = %d\n", pts);
    printf("Next point in %d DA\n", missing);
    printf("Vouchers = %d (%d DA)\n", vouchers, vouchers * 500);
    return 0;
}
