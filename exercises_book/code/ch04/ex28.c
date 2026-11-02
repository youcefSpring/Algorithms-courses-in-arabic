#include <stdio.h>

#define NB 15

int main(void) {
    int times[NB] = {24, 48, 30, 26, 72, 36, 28, 50, 25, 96, 30, 44, 27, 33, 60};
    int index, scan, key, rank;
    for (index = 1; index < NB; index++) {        // ترتيب بالإدراج
        key = times[index];
        for (scan = index - 1; scan >= 0 && times[scan] > key; scan--)
            times[scan + 1] = times[scan];
        times[scan + 1] = key;
    }
    rank = (90 * NB + 99) / 100;      // ceil(0.9 × n) بأعداد صحيحة
    printf("Sorted:");
    for (index = 0; index < NB; index++)
        printf(" %d", times[index]);
    printf("\nP90 = %d hours (rank %d of %d)\n", times[rank - 1], rank, NB);
    return 0;
}
