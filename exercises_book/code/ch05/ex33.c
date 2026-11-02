#include <stdio.h>

#define NB_DEPOTS 3
#define NB_CUST 5

int main(void) {
    int shipCost[NB_DEPOTS][NB_CUST] = {{400, 650, 300, 900, 500},
                                        {550, 300, 450, 600, 700},
                                        {700, 500, 350, 350, 450}};
    int served[NB_DEPOTS] = {0};
    int customer, depot, bestDepot, total = 0;
    for (customer = 0; customer < NB_CUST; customer++) {
        bestDepot = 0;
        for (depot = 1; depot < NB_DEPOTS; depot++)
            if (shipCost[depot][customer] < shipCost[bestDepot][customer])
                bestDepot = depot;
        served[bestDepot]++;
        total += shipCost[bestDepot][customer];
        printf("Customer %d <- depot %d (%d DA)\n", customer, bestDepot,
               shipCost[bestDepot][customer]);
    }
    printf("Total cost = %d DA\n", total);
    for (depot = 0; depot < NB_DEPOTS; depot++)
        printf("Depot %d serves %d customer(s)\n", depot, served[depot]);
    return 0;
}
