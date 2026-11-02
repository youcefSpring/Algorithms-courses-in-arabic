#include <stdio.h>

int main(void) {
    int flags, b0, b1, b2, b3;
    scanf("%d", &flags);
    b0 = flags & 1;               // البت 0: متوفر
    b1 = (flags >> 1) & 1;        // إزاحة لليمين ثم نأخذ آخر بت
    b2 = (flags >> 2) & 1;        // البت 2: شحن مجاني
    b3 = (flags >> 3) & 1;        // البت 3: جديد
    printf("Binary: %d%d%d%d\n", b3, b2, b1, b0);
    printf("In stock: %d\nOn sale: %d\n", b0, b1);
    printf("Free shipping: %d\nNew: %d\n", b2, b3);
    return 0;
}
