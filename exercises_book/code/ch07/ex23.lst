#include <stdio.h>

int countBelow(int stock[], int size, int threshold) {
    int idx, count = 0;
    for (idx = 0; idx < size; idx++)
        if (stock[idx] < threshold) count++;
    return count;
}

void printBelow(int stock[], int size, int threshold) {
    int idx;
    printf("   items:");
    for (idx = 0; idx < size; idx++)
        if (stock[idx] < threshold) printf(" #%d(%d)", idx, stock[idx]);
    printf("\n");
}

int main(void) {
    int stock[8] = {12, 3, 25, 8, 0, 17, 9, 30};
    int thresholds[3] = {5, 10, 20}, level;
    for (level = 0; level < 3; level++) {
        printf("Below %2d: %d products\n", thresholds[level],
               countBelow(stock, 8, thresholds[level]));
        printBelow(stock, 8, thresholds[level]);
    }
    return 0;
}
