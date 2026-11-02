#include <stdio.h>

#define NB 12

int main(void) {
    double price[NB] = {50, 52, 51, 53, 55, 58, 60, 57, 59, 61, 62, 60};
    int index, start = 0, bestStart = 0, bestLen = 1;
    for (index = 1; index < NB; index++) {
        if (price[index] <= price[index - 1])
            start = index;                    // الصعود انقطع
        if (index - start + 1 > bestLen) {
            bestLen = index - start + 1;
            bestStart = start;
        }
    }
    printf("Longest rise: index %d to %d (%d values):",
           bestStart, bestStart + bestLen - 1, bestLen);
    for (index = bestStart; index < bestStart + bestLen; index++)
        printf(" %.0f", price[index]);
    printf("\n");
    return 0;
}
