#include <stdio.h>
#define DELIVERY 400

int main(void) {
    float price = 8900;    /* DA */
    int discount = 15;     /* percent */
    float total = price - price * discount / 100;
    total = total + DELIVERY;
    printf("To pay = %.2f DA\n", total);
    return 0;
}
