#include <stdio.h>

int main(void) {
    int centsA, centsB, totalCents;
    scanf("%d %d", &centsA, &centsB);       // مبلغان بالسنتيم
    totalCents = centsA + centsB;                    // جمع دقيق بلا أخطاء تقريب
    // %02d تضمن ظهور الصفر: 5 سنتيم تكتب 05
    printf("Total = %d.%02d DA\n", totalCents / 100, totalCents % 100);
    return 0;
}
