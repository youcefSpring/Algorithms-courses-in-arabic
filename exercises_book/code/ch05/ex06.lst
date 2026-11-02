#include <stdio.h>

#define NB_DEPOTS 4
#define NB_PRODUCTS 5

int main(void) {
    int stock[NB_DEPOTS][NB_PRODUCTS] = {{5, 0, 12, 3, 8},
                                         {0, 4,  0, 9, 1},
                                         {7, 7,  2, 0, 6},
                                         {3, 0,  5, 5, 0}};
    int depot, product, empty = 0;
    for (depot = 0; depot < NB_DEPOTS; depot++)
        for (product = 0; product < NB_PRODUCTS; product++)
            if (stock[depot][product] == 0) {
                printf("Depot %d, product %d is empty\n", depot, product);
                empty++;
            }
    printf("%d empty slots\n", empty);
    return 0;
}
