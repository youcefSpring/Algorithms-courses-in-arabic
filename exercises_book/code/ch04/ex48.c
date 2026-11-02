#include <stdio.h>

#define NB_B 10
#define NB_P 6

int main(void) {
    // 0 هاتف، 1 غلاف، 2 شاحن، 3 سماعات، 4 ساعة، 5 حاسوب
    int baskets[NB_B] = {0x07, 0x03, 0x0B, 0x01, 0x23, 0x0F, 0x30, 0x03, 0x13, 0x07};
    int single[NB_P] = {0};
    int basket, prod, first, second, pairCount, mask;
    for (basket = 0; basket < NB_B; basket++)
        for (prod = 0; prod < NB_P; prod++)
            if ((baskets[basket] >> prod) & 1)    // هل البت prod يساوي 1؟
                single[prod]++;
    for (first = 0; first < NB_P; first++) {
        for (second = first + 1; second < NB_P; second++) {
            mask = (1 << first) | (1 << second);  // البتان معًا
            pairCount = 0;
            for (basket = 0; basket < NB_B; basket++)
                if ((baskets[basket] & mask) == mask)
                    pairCount++;
            if (pairCount * 100 >= 30 * NB_B)
                printf("{%d,%d}: support %d%%, confidence %d->%d = %.2f\n",
                       first, second, pairCount * 100 / NB_B, first, second,
                       (double)pairCount / single[first]);
        }
    }
    return 0;
}
