#include <stdio.h>

#define NB_PRODUCTS 8

int main(void) {
    int sold[NB_PRODUCTS] = {34, 120, 56, 98, 143, 12, 77, 143};
    int index, best = 0;              // نحفظ الفهرس، لا القيمة
    for (index = 1; index < NB_PRODUCTS; index++)
        if (sold[index] > sold[best])
            best = index;
    printf("Best seller: product #%d with %d units\n", best, sold[best]);
    return 0;
}
