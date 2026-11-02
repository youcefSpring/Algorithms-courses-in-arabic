#include <stdio.h>

int main(void) {
    int qty;
    double price;
    scanf("%lf", &price);
    printf("Qty | Price\n");
    for (qty = 1; qty <= 10; qty++)                 // سطر لكل كمية
        printf("%3d | %8.2f\n", qty, qty * price);
    return 0;
}
