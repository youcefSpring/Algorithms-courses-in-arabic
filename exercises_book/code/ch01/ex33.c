#include <stdio.h>

int main(void) {
    double g1, p1, g2, p2, k1, k2, save;
    scanf("%lf %lf", &g1, &p1);   // الوزن بالغرام والسعر للعبوة 1
    scanf("%lf %lf", &g2, &p2);   // العبوة 2
    k1 = p1 / g1 * 1000;          // سعر الكيلوغرام للعبوة 1
    k2 = p2 / g2 * 1000;          // سعر الكيلوغرام للعبوة 2
    save = (k1 - k2) / k1 * 100;  // التوفير النسبي
    printf("Pack 1: %.2f DA/kg\n", k1);
    printf("Pack 2: %.2f DA/kg\n", k2);
    printf("Difference: %.2f DA/kg (%.1f %% saved)\n", k1 - k2, save);
    return 0;
}
