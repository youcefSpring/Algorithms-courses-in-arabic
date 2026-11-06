#include <stdio.h>

int roundTo(double price, int step) {
    return (int)((price + step / 2.0) / step) * step;   // نصف الخطوة للتقريب
}

int charmPrice(double price) {
    return roundTo(price, 100) - 10;
}

int main(void) {
    double price;
    int step;
    scanf("%lf %d", &price, &step);
    printf("Rounded to %d: %d DA\n", step, roundTo(price, step));
    printf("Rounded to 1000: %d DA\n", roundTo(price, 1000));
    printf("Charm price: %d DA\n", charmPrice(price));
    return 0;
}
