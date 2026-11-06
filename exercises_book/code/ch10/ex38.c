#include <stdio.h>
#include <stdlib.h>

int allocations = 0, releases = 0;
long liveBytes = 0;

void *trackedMalloc(long size) {
    long *block = malloc(size + sizeof(long));
    if (block == NULL) return NULL;
    *block = size;                         // نخزن الحجم قبل البيانات
    allocations++;
    liveBytes += size;
    return block + 1;                      // المستخدم يرى ما بعد الحجم
}

void trackedFree(void *ptr) {
    long *block = (long *)ptr - 1;         // نرجع إلى بداية الكتلة
    liveBytes -= *block;
    releases++;
    free(block);
}

int main(void) {
    double *carts[5];
    int idx, items;
    for (idx = 0; idx < 5; idx++) {
        items = 3 + idx * 2;
        carts[idx] = trackedMalloc(items * sizeof(double));
        carts[idx][0] = 100.0 * items;
    }
    for (idx = 0; idx < 5; idx++)
        if (idx != 1 && idx != 3)          // نسيان تحرير السلتين 1 و 3
            trackedFree(carts[idx]);
    printf("allocations %d, releases %d\n", allocations, releases);
    printf("LEAK: %d blocks, %ld bytes still allocated\n", allocations - releases, liveBytes);
    trackedFree(carts[1]);
    trackedFree(carts[3]);
    printf("after fix: %ld bytes\n", liveBytes);
    return 0;
}
