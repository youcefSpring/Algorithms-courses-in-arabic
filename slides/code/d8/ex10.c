#include <stdio.h>

float total(float price[], int n) {
    if (n == 0)
        return 0;
    return price[n - 1] + total(price, n - 1);
}

int main(void) {
    float cart[5] = {1200, 350.5, 4999, 80, 760};
    printf("Total = %.2f DA\n", total(cart, 5));
    return 0;
}
