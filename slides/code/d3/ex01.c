#include <stdio.h>

int main(void) {
    int i, steps, total = 0;
    for (i = 1; i <= 7; i++) {
        steps = 6000 + i * 750;   /* steps of day i */
        total += steps;
    }
    printf("Total = %d steps\n", total);
    printf("Average = %d steps/day\n", total / 7);
    return 0;
}
