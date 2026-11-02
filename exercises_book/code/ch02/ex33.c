#include <stdio.h>

int main(void) {
    int nbItems;
    double amount;
    scanf("%d %lf", &nbItems, &amount);
    if (nbItems >= 10) {
        printf("Large basket: tote bag");
        if (amount > 20000)           // شرط متداخل
            printf(" + 500 DA voucher");
        printf("\n");
    } else if (nbItems >= 4) {
        printf("Medium basket: tote bag\n");
    } else {
        printf("Small basket: no gift\n");
    }
    return 0;
}
