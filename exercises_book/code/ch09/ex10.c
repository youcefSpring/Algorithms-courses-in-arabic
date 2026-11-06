#include <stdio.h>

typedef struct {
    int items;
    int qty[5];
} Cart;

void show(char label[], Cart basket) {
    int idx;
    printf("%s %d items:", label, basket.items);
    for (idx = 0; idx < basket.items; idx++) printf(" %d", basket.qty[idx]);
    printf("\n");
}

int main(void) {
    Cart cart = {2, {1, 4}};
    Cart backup = cart;                  // نسخة كاملة (بما فيها الجدول)
    cart.qty[0] = 9;
    cart.qty[2] = 2;
    cart.items = 3;
    show("cart:  ", cart);
    show("backup:", backup);
    return 0;
}
