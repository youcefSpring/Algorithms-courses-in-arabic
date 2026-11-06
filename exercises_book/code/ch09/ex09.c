#include <stdio.h>

typedef struct {
    int hours, minutes, seconds;
} Duration;

Duration addDurations(Duration first, Duration second) {
    Duration sum;
    sum.seconds = first.seconds + second.seconds;
    sum.minutes = first.minutes + second.minutes + sum.seconds / 60;   // ترحيل
    sum.seconds %= 60;
    sum.hours = first.hours + second.hours + sum.minutes / 60;
    sum.minutes %= 60;
    return sum;
}

int main(void) {
    Duration sessions[3] = {{0, 42, 35}, {1, 18, 50}, {0, 55, 47}};
    Duration total = {0, 0, 0};
    int idx;
    for (idx = 0; idx < 3; idx++)
        total = addDurations(total, sessions[idx]);
    printf("Total browsing time: %dh %02dm %02ds\n", total.hours, total.minutes, total.seconds);
    return 0;
}
