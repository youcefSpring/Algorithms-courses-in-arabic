#include <stdio.h>
#include <stdlib.h>

#define NB 20

int main(void) {
    int ages[NB] = {19, 23, 31, 45, 52, 27, 34, 22, 61, 38, 29, 47, 25, 33, 56, 41, 21, 36, 30, 66};
    int low = 18, high = 67, bins, query, idx, bin, star, *counts;
    for (query = 0; query < 2; query++) {
        scanf("%d", &bins);
        counts = malloc(bins * sizeof(int));              // حجم يحدده المستخدم
        for (bin = 0; bin < bins; bin++) counts[bin] = 0;
        for (idx = 0; idx < NB; idx++) counts[(ages[idx] - low) * bins / (high - low + 1)]++;
        printf("%d bins:\n", bins);
        for (bin = 0; bin < bins; bin++) {
            printf("  %2d-%2d |", low + bin * (high - low + 1) / bins,
                   low + (bin + 1) * (high - low + 1) / bins - 1);
            for (star = 0; star < counts[bin]; star++) putchar('#');
            printf(" %d\n", counts[bin]);
        }
        free(counts);
    }
    return 0;
}
