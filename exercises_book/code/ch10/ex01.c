#include <stdio.h>

int main(void) {
    double price = 4500;
    double *ptr = &price;                    // ptr يحمل عنوان price
    printf("price = %.2f, *ptr = %.2f\n", price, *ptr);
    printf("same address: %s\n", ptr == &price ? "yes" : "no");
    *ptr = *ptr * 0.9;                       // نعدل price عبر المؤشر
    printf("after -10%% via pointer: price = %.2f\n", price);
    return 0;
}
