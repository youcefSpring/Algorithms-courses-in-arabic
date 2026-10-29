#include <stdio.h>

float discount(float price, int percent) {
    return price * (100 - percent) / 100;
}

float withTax(float price) {
    return price * 1.19;
}

int main(void) {
    float p = withTax(discount(12000, 20));
    printf("Final price = %.2f DA\n", p);
    return 0;
}
