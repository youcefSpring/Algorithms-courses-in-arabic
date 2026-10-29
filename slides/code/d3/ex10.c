#include <stdio.h>

int main(void) {
    long views = 100;
    int hour = 0;
    while (views < 1000000) {
        views *= 3;
        hour++;
    }
    printf("1 million views after %d hours\n", hour);
    printf("Views = %ld\n", views);
    return 0;
}
