#include <stdio.h>

#define NB_STORES 3
#define NB_DAYS 4

int main(void) {
    int sales[NB_STORES][NB_DAYS] = {{120, 95, 140, 180},
                                     { 80, 60,  75,  90},
                                     {200, 210, 190, 250}};
    int store, day, dayTotal;
    for (day = 0; day < NB_DAYS; day++) {         // الأعمدة في الخارج
        dayTotal = 0;
        for (store = 0; store < NB_STORES; store++)
            dayTotal += sales[store][day];
        printf("Day %d: %d\n", day + 1, dayTotal);
    }
    return 0;
}
