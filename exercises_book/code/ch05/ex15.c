#include <stdio.h>

#define NB_STORES 3
#define NB_DAYS 6

int main(void) {
    int sales[NB_STORES][NB_DAYS] = {{120, 95, 140, 180, 90, 210},
                                     {130, 60, 175,  90, 95, 100},
                                     {100, 99, 150, 170, 80, 240}};
    int wins[NB_STORES] = {0};
    int day, store, winner;
    for (day = 0; day < NB_DAYS; day++) {
        winner = 0;                       // نبحث في العمود day
        for (store = 1; store < NB_STORES; store++)
            if (sales[store][day] > sales[winner][day])
                winner = store;
        wins[winner]++;
        printf("Day %d: store %d\n", day + 1, winner);
    }
    for (store = 0; store < NB_STORES; store++)
        printf("Store %d won %d day(s)\n", store, wins[store]);
    return 0;
}
