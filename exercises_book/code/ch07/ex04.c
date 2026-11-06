#include <stdio.h>

int isAvailable(int stock, int ordered) {
    return ordered <= stock;          // 1 أو 0
}

int main(void) {
    int stock[4] = {10, 0, 5, 7};
    int ordered[4] = {3, 1, 5, 9};
    int order;
    for (order = 0; order < 4; order++) {
        if (isAvailable(stock[order], ordered[order]))
            printf("Order %d: OK\n", order + 1);
        else
            printf("Order %d: out of stock (%d left)\n", order + 1, stock[order]);
    }
    return 0;
}
