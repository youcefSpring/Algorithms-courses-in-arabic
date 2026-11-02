#include <stdio.h>

#define NB_IDS 12

int main(void) {
    int catalog[NB_IDS] = {1001, 1203, 2210, 3001, 3550, 4410, 5512,
                6600, 7781, 8120, 9045, 9900};      // مرتب
    int target, lo = 0, hi = NB_IDS - 1, mid, pos = -1, cmp = 0;
    scanf("%d", &target);
    while (lo <= hi && pos == -1) {
        mid = (lo + hi) / 2;
        cmp++;
        if (catalog[mid] == target)
            pos = mid;
        else if (catalog[mid] < target)
            lo = mid + 1;         // target في النصف الأيمن
        else
            hi = mid - 1;         // target في النصف الأيسر
    }
    if (pos >= 0)
        printf("Found at index %d after %d comparisons\n", pos, cmp);
    else
        printf("Not found (%d comparisons)\n", cmp);
    return 0;
}
