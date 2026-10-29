#include <stdio.h>
#define CO2_PER_KM 0.12   /* kg */

int main(void) {
    int km_per_day = 40, days = 22;
    float co2 = km_per_day * days * CO2_PER_KM;
    printf("CO2 per month = %.1f kg\n", co2);
    printf("Trees needed = %d\n", (int) (co2 * 12 / 25));
    return 0;
}
