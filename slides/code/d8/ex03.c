#include <stdio.h>

double trees(int year) {
    if (year == 0)
        return 1000;
    return trees(year - 1) * 1.2 + 50;
}

int main(void) {
    int y;
    for (y = 0; y <= 5; y++)
        printf("Year %d: %.0f trees\n", y, trees(y));
    return 0;
}
