#include <stdio.h>

#define NB_PAGES 8

int main(void) {
    int visits[NB_PAGES] = {340, 1200, 85, 960, 1200, 410, 77, 2300};
    int index, scan, maxPos, tmp;
    for (index = 0; index < NB_PAGES - 1; index++) {
        maxPos = index;                    // فهرس الأكبر في visits[index..N-1]
        for (scan = index + 1; scan < NB_PAGES; scan++)
            if (visits[scan] > visits[maxPos])
                maxPos = scan;
        tmp = visits[index]; visits[index] = visits[maxPos]; visits[maxPos] = tmp;  // نضعه في الموضع index
    }
    printf("Pages by visits:");
    for (index = 0; index < NB_PAGES; index++)
        printf(" %d", visits[index]);
    printf("\n");
    return 0;
}
