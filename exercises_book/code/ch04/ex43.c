#include <stdio.h>

#define NB 10

int main(void) {
    int times[NB] = {120, 45, 300, 80, 95, 15, 210, 60, 33, 150};
    int buffer[NB];
    int width, left, mid, right, posA, posB, out, index;
    for (width = 1; width < NB; width *= 2) {         // طول الأجزاء المرتبة
        for (left = 0; left < NB; left += 2 * width) {
            mid = (left + width < NB) ? left + width : NB;
            right = (left + 2 * width < NB) ? left + 2 * width : NB;
            posA = left; posB = mid; out = left;
            while (posA < mid && posB < right)        // دمج جزأين مرتبين
                buffer[out++] = (times[posA] <= times[posB]) ? times[posA++] : times[posB++];
            while (posA < mid)   buffer[out++] = times[posA++];
            while (posB < right) buffer[out++] = times[posB++];
        }
        for (index = 0; index < NB; index++)
            times[index] = buffer[index];
        printf("width %d:", width);
        for (index = 0; index < NB; index++)
            printf(" %d", times[index]);
        printf("\n");
    }
    return 0;
}
