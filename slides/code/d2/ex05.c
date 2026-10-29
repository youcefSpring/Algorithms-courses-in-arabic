#include <stdio.h>
#define FREE_FROM 5000

int main(void) {
    float total = 4200, delivery;
    if (total >= FREE_FROM)
        delivery = 0;
    else
        delivery = 400;
    printf("Delivery = %.0f DA\n", delivery);
    printf("To pay = %.0f DA\n", total + delivery);
    return 0;
}
