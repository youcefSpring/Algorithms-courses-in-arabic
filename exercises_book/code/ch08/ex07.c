#include <stdio.h>

double maxPrice(double prices[], int size) {
    double rest;
    if (size == 1)
        return prices[0];
    rest = maxPrice(prices, size - 1);                 // أكبر الباقي
    return prices[size - 1] > rest ? prices[size - 1] : rest;
}

int main(void) {
    double prices[6] = {4500, 1200, 27000, 899, 12500, 650};
    printf("Most expensive: %.0f DA\n", maxPrice(prices, 6));
    return 0;
}
