#include <stdio.h>

#define NB_STORES 3
#define NB_DAYS 4

int main(void) {
    int sales[NB_STORES][NB_DAYS] = {{120, 95, 140, 180},
                                     { 80, 60,  75,  90},
                                     {200, 210, 190, 250}};
    int store, day, bestStore = 0, bestDay = 0;
    for (store = 0; store < NB_STORES; store++)
        for (day = 0; day < NB_DAYS; day++)
            if (sales[store][day] > sales[bestStore][bestDay]) {
                bestStore = store;        // نحفظ الإحداثيتين
                bestDay = day;
            }
    printf("Best: store %d, day %d -> %d\n", bestStore, bestDay + 1,
           sales[bestStore][bestDay]);
    return 0;
}
