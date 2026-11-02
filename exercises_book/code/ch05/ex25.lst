#include <stdio.h>

int main(void) {
    int orders[7][6] = {{ 2,  5, 14, 10, 18, 25},
                        { 1,  6, 12,  9, 20, 22},
                        { 3,  4, 15, 11, 17, 28},
                        { 2,  7, 13, 12, 21, 30},
                        { 5,  9, 20, 16, 26, 38},
                        { 8, 15, 25, 22, 30, 41},
                        { 7, 12, 22, 18, 24, 29}};
    int day, slot, level, peak = 0;
    char symbol;
    for (day = 0; day < 7; day++)
        for (slot = 0; slot < 6; slot++)
            if (orders[day][slot] > peak)
                peak = orders[day][slot];
    printf("     0-4 4-8 8-12 12-16 16-20 20-24\n");
    for (day = 0; day < 7; day++) {
        printf("Day %d ", day + 1);
        for (slot = 0; slot < 6; slot++) {
            level = orders[day][slot] * 4 / (peak + 1);   // 0..3
            switch (level) {
                case 0:  symbol = '.'; break;
                case 1:  symbol = '-'; break;
                case 2:  symbol = '+'; break;
                default: symbol = '#';
            }
            printf("  %c  ", symbol);
        }
        printf("\n");
    }
    return 0;
}
