#include <stdio.h>

int main(void) {
    long contLength, contWidth, contHeight, boxLength, boxWidth, boxHeight, nx, ny, nz, nbBoxes, used;
    double pct;
    scanf("%ld %ld %ld", &contLength, &contWidth, &contHeight);     // أبعاد الحاوية
    scanf("%ld %ld %ld", &boxLength, &boxWidth, &boxHeight);     // أبعاد العلبة
    nx = contLength / boxLength;                   // علب على الطول
    ny = contWidth / boxWidth;                   // علب على العرض
    nz = contHeight / boxHeight;                   // طبقات على الارتفاع
    nbBoxes = nx * ny * nz;             // العدد الكلي
    used = nbBoxes * boxLength * boxWidth * boxHeight;         // الحجم المشغول بالعلب
    pct = (double)used / (contLength * contWidth * contHeight) * 100;
    printf("Grid: %ld x %ld x %ld\n", nx, ny, nz);
    printf("Boxes = %ld\n", nbBoxes);
    printf("Volume used = %.2f %%\n", pct);
    return 0;
}
