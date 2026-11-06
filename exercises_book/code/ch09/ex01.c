#include <stdio.h>

struct Product {
    int code;
    char name[30];
    double price;
    int stock;
};

int main(void) {
    struct Product item = {2045, "Smartphone X", 32000, 14};   // تهيئة بالترتيب
    printf("Code : %d\n", item.code);
    printf("Name : %s\n", item.name);
    printf("Price: %.2f DA\n", item.price);
    printf("Stock: %d units\n", item.stock);
    printf("Stock value: %.2f DA\n", item.price * item.stock);
    return 0;
}
