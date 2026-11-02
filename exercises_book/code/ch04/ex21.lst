#include <stdio.h>

#define NB_ORDERS 20

int main(void) {
    int hours[NB_ORDERS] = {9, 12, 13, 20, 21, 12, 20, 22, 8, 13,
                    20, 21, 12, 19, 20, 23, 13, 20, 10, 21};
    int cnt[24] = {0};
    int index, hour, bar, peak = 0;
    for (index = 0; index < NB_ORDERS; index++)
        cnt[hours[index]]++;
    for (hour = 0; hour < 24; hour++) {
        if (cnt[hour] > 0) {
            printf("%02dh | ", hour);
            for (bar = 0; bar < cnt[hour]; bar++)
                printf("#");
            printf(" %d\n", cnt[hour]);
        }
        if (cnt[hour] > cnt[peak])
            peak = hour;
    }
    printf("Peak hour: %02dh\n", peak);
    return 0;
}
