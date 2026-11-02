#include <stdio.h>

int main(void) {
    long code, work, rev = 0;
    scanf("%ld", &code);
    work = code;                        // نعمل على نسخة
    while (work > 0) {
        rev = rev * 10 + work % 10;  // نلصق آخر رقم في نهاية rev
        work = work / 10;
    }
    printf("Reversed: %ld\n", rev);
    if (rev == code)
        printf("%ld is a valid palindrome code\n", code);
    else
        printf("%ld is not a palindrome\n", code);
    return 0;
}
