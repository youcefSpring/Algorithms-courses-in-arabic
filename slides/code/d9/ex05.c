#include <stdio.h>

typedef struct { char n[10]; float price; int qty; } Item;

int main(void) {
    Item p[4] = {{"Laptop", 89000, 4},
                 {"Mouse", 1500, 40},
                 {"Screen", 32000, 2},
                 {"Cable", 600, 75}};
    int i;
    float value = 0;
    for (i = 0; i < 4; i++) {
        value += p[i].price * p[i].qty;
        if (p[i].qty < 5)
            printf("Low stock: %s\n", p[i].n);
    }
    printf("Stock value = %.0f DA\n", value);
    return 0;
}
