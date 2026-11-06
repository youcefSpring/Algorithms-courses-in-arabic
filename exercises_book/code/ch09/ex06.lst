#include <stdio.h>

typedef struct {
    char name[20];
    double price;
    int stock;
} Product;

int main(void) {
    Product items[5] = {{"Laptop", 89000, 4}, {"Mouse", 1500, 0}, {"Monitor", 32000, 6},
                        {"Keyboard", 3200, 15}, {"Webcam", 4100, 0}};
    double value = 0;
    int idx, outOfStock = 0;
    for (idx = 0; idx < 5; idx++) {
        value += items[idx].price * items[idx].stock;
        if (items[idx].stock == 0) {
            outOfStock++;
            printf("Out of stock: %s\n", items[idx].name);
        }
    }
    printf("Inventory value: %.2f DA\n", value);
    printf("%d product(s) to reorder\n", outOfStock);
    return 0;
}
