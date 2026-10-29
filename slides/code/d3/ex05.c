#include <stdio.h>

int main(void) {
    float pm = 120;   /* pollution index */
    int year = 0;
    while (pm >= 50) {
        pm = pm * 0.85;   /* -15 % per year */
        year++;
        printf("Year %d: %.1f\n", year, pm);
    }
    return 0;
}
