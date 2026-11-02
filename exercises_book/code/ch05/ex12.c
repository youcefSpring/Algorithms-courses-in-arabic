#include <stdio.h>

#define NB 3

int main(void) {
    int jan[NB][NB] = {{120, 80, 60}, {40, 55, 70}, {300, 210, 150}};
    int feb[NB][NB] = {{132, 70, 66}, {52, 55, 63}, {330, 240, 150}};
    int total[NB][NB], product, store;
    for (product = 0; product < NB; product++) {
        for (store = 0; store < NB; store++) {
            total[product][store] = jan[product][store] + feb[product][store];
            printf("%4d (%+5.1f%%)", total[product][store],
                   (feb[product][store] - jan[product][store]) * 100.0 / jan[product][store]);
        }
        printf("\n");
    }
    return 0;
}
