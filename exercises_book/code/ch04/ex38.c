#include <stdio.h>

#define DIGITS 25

int main(void) {
    int numA[DIGITS], numB[DIGITS], result[DIGITS + 1];
    int pos, sum, carry = 0;
    char digit;
    for (pos = DIGITS - 1; pos >= 0; pos--) {     // الآحاد في الخانة 0
        scanf(" %c", &digit);
        numA[pos] = digit - '0';      // تحويل الحرف إلى رقم
    }
    for (pos = DIGITS - 1; pos >= 0; pos--) {
        scanf(" %c", &digit);
        numB[pos] = digit - '0';
    }
    for (pos = 0; pos < DIGITS; pos++) {
        sum = numA[pos] + numB[pos] + carry;
        result[pos] = sum % 10;       // الرقم المكتوب
        carry = sum / 10;             // الاحتفاظ للموضع التالي
    }
    result[DIGITS] = carry;
    pos = (carry > 0) ? DIGITS : DIGITS - 1;   // نتجاهل الصفر البادئ
    printf("Sum = ");
    for (; pos >= 0; pos--)
        printf("%d", result[pos]);
    printf("\n");
    return 0;
}
