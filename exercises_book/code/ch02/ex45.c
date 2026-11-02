#include <stdio.h>

int main(void) {
    int year, d1, m1, d2, m2, n1, n2, leap, diff;
    scanf("%d %d %d %d %d", &year, &d1, &m1, &d2, &m2);
    leap = (year % 4 == 0 && year % 100 != 0) || year % 400 == 0;

    n1 = d1;
    switch (m1 - 1) {         // دون break: نجمع كل الأشهر السابقة
        case 11: n1 += 30;    // نوفمبر
        // fall through
        case 10: n1 += 31;
        // fall through
        case 9:  n1 += 30;
        // fall through
        case 8:  n1 += 31;
        // fall through
        case 7:  n1 += 31;
        // fall through
        case 6:  n1 += 30;
        // fall through
        case 5:  n1 += 31;
        // fall through
        case 4:  n1 += 30;
        // fall through
        case 3:  n1 += 31;
        // fall through
        case 2:  n1 += 28 + leap;   // فيفري
        // fall through
        case 1:  n1 += 31;          // جانفي
    }
    n2 = d2;
    switch (m2 - 1) {         // نفس الطريقة للتاريخ الثاني
        case 11: n2 += 30;
        // fall through
        case 10: n2 += 31;
        // fall through
        case 9:  n2 += 30;
        // fall through
        case 8:  n2 += 31;
        // fall through
        case 7:  n2 += 31;
        // fall through
        case 6:  n2 += 30;
        // fall through
        case 5:  n2 += 31;
        // fall through
        case 4:  n2 += 30;
        // fall through
        case 3:  n2 += 31;
        // fall through
        case 2:  n2 += 28 + leap;
        // fall through
        case 1:  n2 += 31;
    }
    diff = n2 - n1;
    if (diff < 0)
        diff = -diff;
    printf("Day numbers: %d and %d\n", n1, n2);
    printf("Days between = %d\n", diff);
    return 0;
}
