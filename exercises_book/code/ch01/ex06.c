#include <stdio.h>

int main(void) {
    double price, rate, disc, newPrice;
    scanf("%lf %lf", &price, &rate);
    disc = price * rate / 100;    // قيمة التخفيض
    newPrice = price - disc;      // السعر بعد التخفيض
    printf("Discount = %.2f DA\n", disc);
    printf("New price = %.2f DA\n", newPrice);
    return 0;
}
