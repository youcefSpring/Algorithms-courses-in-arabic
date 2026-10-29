#include <stdio.h>
#define KWH_PRICE 4.2   /* DA per kWh */

int main(void) {
    int power = 1500;     /* W */
    float hours = 6.5;
    float kwh = power * hours / 1000;
    printf("Energy = %.2f kWh\n", kwh);
    printf("Cost = %.2f DA\n", kwh * KWH_PRICE);
    return 0;
}
