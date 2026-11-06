#include <stdio.h>

typedef struct {
    char name[20];
    double price;
} Product;

Product applyDiscount(Product item, double percent) {
    item.price = item.price * (100 - percent) / 100;   // نعدل النسخة فقط
    return item;
}

int main(void) {
    Product item = {"Headphones", 12500};
    Product promo = applyDiscount(item, 20);
    printf("Original: %s %.2f DA\n", item.name, item.price);
    printf("Promo:    %s %.2f DA\n", promo.name, promo.price);
    return 0;
}
