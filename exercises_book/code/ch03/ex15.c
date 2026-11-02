#include <stdio.h>

int main(void) {
    int nbProducts, size, step;
    long long bundles = 1;
    scanf("%d %d", &nbProducts, &size);
    for (step = 1; step <= size; step++) {
        // بعد هذه الخطوة bundles = C(nbProducts-size+step, step)، عدد صحيح دائمًا
        bundles = bundles * (nbProducts - size + step) / step;
    }
    printf("Bundles C(%d,%d) = %lld\n", nbProducts, size, bundles);
    return 0;
}
