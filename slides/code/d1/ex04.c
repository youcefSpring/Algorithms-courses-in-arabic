#include <stdio.h>
#define FUEL_PRICE 45.6   /* DA per liter */

int main(void) {
    float km = 350, liters = 24.5;
    float per100 = liters / km * 100;
    printf("Consumption = %.1f L/100km\n", per100);
    printf("Trip cost = %.2f DA\n", liters * FUEL_PRICE);
    return 0;
}
