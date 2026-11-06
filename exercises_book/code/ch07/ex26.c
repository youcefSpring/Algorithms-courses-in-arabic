#include <stdio.h>

long reverseNumber(long number) {
    long reversed = 0;
    while (number > 0) {
        reversed = reversed * 10 + number % 10;   // آخر رقم ينتقل إلى اليسار
        number /= 10;
    }
    return reversed;
}

int isPalindrome(long number) {
    return reverseNumber(number) == number;
}

int main(void) {
    long invoices[6] = {12321, 20452, 45654, 100001, 98760, 7};
    int idx;
    for (idx = 0; idx < 6; idx++) {
        if (isPalindrome(invoices[idx]))
            printf("Invoice %6ld: palindrome -> gift!\n", invoices[idx]);
        else
            printf("Invoice %6ld: reversed %ld\n", invoices[idx], reverseNumber(invoices[idx]));
    }
    return 0;
}
