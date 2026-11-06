#include <stdio.h>

typedef struct {
    char name[20];
    double price;
    int qty;
} OrderLine;

int main(void) {
    OrderLine lines[4] = {{"USB cable", 450, 3}, {"Charger", 2200, 1},
                          {"Case", 900, 2}, {"Screen film", 350, 4}};
    double total = 0, amount;
    int idx;
    for (idx = 0; idx < 4; idx++) {
        amount = lines[idx].price * lines[idx].qty;
        total += amount;
        printf("%-12s %2d x %7.2f = %8.2f\n", lines[idx].name, lines[idx].qty,
               lines[idx].price, amount);
    }
    printf("TOTAL %30.2f DA\n", total);
    return 0;
}
