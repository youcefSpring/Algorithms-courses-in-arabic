#include <stdio.h>

int sell(int *stock, int qty) {
    if (*stock < qty)
        return 0;                     // مخزون غير كافٍ
    *stock -= qty;
    return 1;
}

int main(void) {
    int stock = 10, orders[4] = {3, 5, 4, 2}, idx, ok;
    for (idx = 0; idx < 4; idx++) {
        ok = sell(&stock, orders[idx]);
        printf("Sell %d: %s, stock now %d\n", orders[idx], ok ? "OK" : "refused", stock);
    }
    return 0;
}
