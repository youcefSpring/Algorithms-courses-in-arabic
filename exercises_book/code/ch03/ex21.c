#include <stdio.h>

int main(void) {
    long prev = 1, current = 1, next, total = 2, target;
    int month = 2;
    scanf("%ld", &target);
    printf("Month 1: 1\nMonth 2: 1\n");
    while (current <= target) {
        next = prev + current;                // الشهر الجديد = مجموع الشهرين السابقين
        prev = current;                    // نزيح النافذة
        current = next;
        total += next;
        month++;
        printf("Month %d: %ld\n", month, next);
    }
    printf("Total users after %d months: %ld\n", month, total);
    return 0;
}
