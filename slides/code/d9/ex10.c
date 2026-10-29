#include <stdio.h>

typedef struct { char model[10]; int km; float co2; } Car;
/* co2 in kg per km */

int main(void) {
    Car f[3] = {{"Diesel", 30000, 0.15},
                {"Hybrid", 25000, 0.09},
                {"Electric", 28000, 0.02}};
    int i;
    float total = 0;
    for (i = 0; i < 3; i++)
        total += f[i].km * f[i].co2;
    printf("Fleet CO2 = %.0f kg/year\n", total);
    return 0;
}
