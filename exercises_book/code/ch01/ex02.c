#include <stdio.h>

int main(void) {
    double price, amount;         // سعر الوحدة ومبلغ السطر
    int qty;                      // الكمية عدد صحيح
    scanf("%lf %d", &price, &qty);
    amount = price * qty;         // المبلغ = السعر × الكمية
    printf("%d x %.2f = %.2f DA\n", qty, price, amount);
    return 0;
}
