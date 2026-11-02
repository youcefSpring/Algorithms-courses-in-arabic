#include <stdio.h>

#define NB_STORES 3
#define NB_DAYS 4

int main(void) {
    int sales[NB_STORES][NB_DAYS] = {{120, 95, 140, 180},
                                     { 80, 60,  75,  90},
                                     {200, 210, 190, 250}};
    int store, day, total = 0;
    for (store = 0; store < NB_STORES; store++)
        for (day = 0; day < NB_DAYS; day++)
            total += sales[store][day];   // كل خانة مرة واحدة
    printf("Total = %d\n", total);
    printf("Average per cell = %.2f\n", (double)total / (NB_STORES * NB_DAYS));
    return 0;
}
