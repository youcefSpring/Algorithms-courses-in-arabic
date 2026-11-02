#include <stdio.h>

int main(void) {
    int number, n0, bit, ones = 0;
    long long bin = 0, place = 1;
    scanf("%d", &number);
    n0 = number;
    while (number > 0) {
        bit = number % 2;                // البت الأقل وزنًا
        ones += bit;
        bin = bin + bit * place;        // نضعه في موضعه العشري
        place = place * 10;
        number = number / 2;                // ننتقل إلى البت الموالي
    }
    printf("%d in binary = %lld (%d ones)\n", n0, bin, ones);
    return 0;
}
