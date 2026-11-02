#include <stdio.h>

int main(void) {
    unsigned long long number, power = 1;
    int digit;
    scanf("%llu", &number);
    printf("%llu = 0x", number);
    while (power * 16 <= number)           // أكبر قوة لـ 16 لا تتجاوز number
        power *= 16;
    while (power > 0) {
        digit = number / power;                // الرقم الحالي من اليسار
        number = number % power;
        if (digit < 10)
            putchar('0' + digit);     // 0..9
        else
            putchar('A' + digit - 10);// A..F
        power /= 16;
    }
    printf("\n");
    return 0;
}
