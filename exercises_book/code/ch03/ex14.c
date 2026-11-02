#include <stdio.h>

int main(void) {
    int nbProducts, slots, step;
    long long arr = 1, fact = 1;  // long long لتجنب تجاوز السعة
    scanf("%d %d", &nbProducts, &slots);
    for (step = 0; step < slots; step++)
        arr *= (nbProducts - step);           // nbProducts × (nbProducts-1) × ... (slots عوامل)
    for (step = 2; step <= nbProducts; step++)
        fact *= step;                // nbProducts!
    printf("Arrangements A(%d,%d) = %lld\n", nbProducts, slots, arr);
    printf("%d! = %lld\n", nbProducts, fact);
    return 0;
}
