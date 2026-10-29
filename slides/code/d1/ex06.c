#include <stdio.h>

int main(void) {
    int capacity = 5000;   /* mAh */
    int usage = 420;       /* mA */
    float hours = (float) capacity / usage;
    printf("Autonomy = %.1f hours\n", hours);
    printf("Full hours = %d\n", capacity / usage);
    return 0;
}
