#include <stdio.h>

int main(void) {
    double price, r2;
    int r10;
    scanf("%lf", &price);
    // إضافة 0.5 ثم الحذف بالتحويل إلى int = تقريب لأقرب عدد صحيح
    r2 = (int)(price * 100 + 0.5) / 100.0;
    r10 = (int)(price / 10 + 0.5) * 10;     // تقريب لأقرب 10 دنانير
    printf("Rounded (2 decimals) = %.4f\n", r2);
    printf("Rounded (10 DA) = %d\n", r10);
    return 0;
}
