#include <stdio.h>

int main(void) {
    int slots[5][8] = {{1, 1, 0, 0, 1, 0, 1, 1},
                       {0, 1, 1, 0, 0, 1, 0, 0},
                       {1, 0, 0, 0, 0, 1, 1, 0},
                       {0, 0, 0, 1, 1, 1, 1, 1},
                       {1, 1, 1, 1, 1, 1, 1, 1}};
    int need, day, slot, run, found = 0, start = 0, bookDay = 0, pos;
    scanf("%d", &need);
    for (day = 0; day < 5 && !found; day++) {
        run = 0;                          // طول السلسلة الحرة الحالية
        for (slot = 0; slot < 8 && !found; slot++) {
            if (slots[day][slot] == 0) run++;
            else run = 0;
            if (run == need) {
                found = 1;
                start = slot - need + 1;
                bookDay = day;
            }
        }
    }
    if (!found) {
        printf("No %d consecutive free slots\n", need);
    } else {
        for (pos = start; pos < start + need; pos++)
            slots[bookDay][pos] = 1;      // الحجز
        printf("Booked day %d, slots %d to %d:", bookDay + 1, start, start + need - 1);
        for (pos = 0; pos < 8; pos++)
            printf(" %d", slots[bookDay][pos]);
        printf("\n");
    }
    return 0;
}
