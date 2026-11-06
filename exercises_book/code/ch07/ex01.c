#include <stdio.h>

double priceWithTax(double price) {
    return price * 1.19;              // 19% TVA
}

int main(void) {
    double prices[3] = {1200, 4500, 89.9};
    int item;
    for (item = 0; item < 3; item++)
        printf("%8.2f DA -> %8.2f DA\n", prices[item], priceWithTax(prices[item]));
    return 0;
}
