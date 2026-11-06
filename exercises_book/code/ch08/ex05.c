#include <stdio.h>

double basketTotal(double prices[], int size) {
    if (size == 0)
        return 0;                                          // سلة فارغة
    return prices[size - 1] + basketTotal(prices, size - 1);
}

int main(void) {
    double prices[5] = {1200, 450, 3999, 89.5, 700};
    printf("Basket total: %.2f DA\n", basketTotal(prices, 5));
    printf("First 3 items: %.2f DA\n", basketTotal(prices, 3));
    return 0;
}
