#include <stdio.h>

int main(void) {
    int season = 3;   /* 1 winter ... 4 autumn */
    int hours;
    switch (season) {
        case 1:  hours = 4; break;
        case 2:
        case 4:  hours = 6; break;
        case 3:  hours = 9; break;
        default: hours = 0;
    }
    printf("Production = %d kWh/day\n", hours * 3);
    return 0;
}
