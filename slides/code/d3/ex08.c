#include <stdio.h>

int main(void) {
    int battery = 100, hour = 0;
    do {
        battery -= 7;
        hour++;
    } while (battery > 20);
    printf("After %d hours\n", hour);
    printf("Battery = %d %%\n", battery);
    return 0;
}
