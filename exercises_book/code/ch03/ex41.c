#include <stdio.h>

int main(void) {
    int limit, number, divisor, isp, count = 0, sum = 0;
    scanf("%d", &limit);
    if (limit >= 2) {                     // 2 هو العدد الأولي الزوجي الوحيد
        printf("2 ");
        count = 1; sum = 2;
    }
    for (number = 3; number <= limit; number += 2) {     // الأعداد الفردية فقط
        isp = 1;
        for (divisor = 3; isp && divisor * divisor <= number; divisor += 2)
            if (number % divisor == 0)
                isp = 0;              // له قاسم: ليس أوليًا
        if (isp) {
            printf("%d ", number);
            count++;
            sum += number;
        }
    }
    printf("\n%d primes, sum = %d\n", count, sum);
    return 0;
}
