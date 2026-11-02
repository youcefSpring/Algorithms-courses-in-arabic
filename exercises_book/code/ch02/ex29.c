#include <stdio.h>

int main(void) {
    int a1, b1, a2, b2, overlapStart, overlapEnd;
    scanf("%d %d %d %d", &a1, &b1, &a2, &b2);
    overlapStart = (a1 > a2) ? a1 : a2;      // البداية الأكبر
    overlapEnd = (b1 < b2) ? b1 : b2;      // النهاية الأصغر
    if (overlapStart <= overlapEnd)
        printf("Overlap: days %d to %d (%d days)\n", overlapStart, overlapEnd, overlapEnd - overlapStart + 1);
    else
        printf("No overlap\n");
    return 0;
}
