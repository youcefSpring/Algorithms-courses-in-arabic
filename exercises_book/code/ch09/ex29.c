#include <stdio.h>

typedef struct { int code; double price; int qty; } CartItem;
typedef struct { CartItem items[10]; int count; } Cart;

void addItem(Cart cart[], int code, double price, int qty) {
    int idx;
    for (idx = 0; idx < cart[0].count; idx++)
        if (cart[0].items[idx].code == code) { cart[0].items[idx].qty += qty; return; }
    cart[0].items[cart[0].count].code = code;           // سطر جديد
    cart[0].items[cart[0].count].price = price;
    cart[0].items[cart[0].count].qty = qty;
    cart[0].count++;
}

void removeItem(Cart cart[], int code) {
    int idx, found = -1;
    for (idx = 0; idx < cart[0].count; idx++)
        if (cart[0].items[idx].code == code) found = idx;
    if (found < 0) return;
    for (idx = found; idx < cart[0].count - 1; idx++)
        cart[0].items[idx] = cart[0].items[idx + 1];      // إزاحة
    cart[0].count--;
}

double cartTotal(Cart cart[]) {
    double total = 0;
    int idx;
    for (idx = 0; idx < cart[0].count; idx++)
        total += cart[0].items[idx].price * cart[0].items[idx].qty;
    return total;
}

void show(Cart cart[]) {
    int idx;
    for (idx = 0; idx < cart[0].count; idx++)
        printf("[%d x%d] ", cart[0].items[idx].code, cart[0].items[idx].qty);
    printf("= %.2f DA\n", cartTotal(cart));
}

int main(void) {
    Cart cart[1];
    cart[0].count = 0;
    addItem(cart, 101, 1500, 2); show(cart);
    addItem(cart, 205, 3200, 1); show(cart);
    addItem(cart, 330, 899, 3);  show(cart);
    addItem(cart, 101, 1500, 1); show(cart);
    removeItem(cart, 205);       show(cart);
    return 0;
}
