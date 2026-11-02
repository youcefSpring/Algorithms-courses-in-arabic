#include <stdio.h>

#define NB_ITEMS 5

int main(void) {
    double price[NB_ITEMS] = {350, 1200, 80, 4500, 999};
    int qty[NB_ITEMS] = {2, 0, 10, 1, 3};    // جدولان متوازيان
    double total = 0, line;
    int index;
    for (index = 0; index < NB_ITEMS; index++) {
        if (qty[index] > 0) {
            line = price[index] * qty[index];
            printf("Item %d: %d x %.2f = %.2f\n", index, qty[index], price[index], line);
            total += line;
        }
    }
    printf("TOTAL = %.2f DA\n", total);
    return 0;
}
