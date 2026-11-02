#include <stdio.h>

int main(void) {
    int stock, quantity;
    scanf("%d %d", &stock, &quantity);       // المخزون والكمية المطلوبة
    if (quantity <= stock) {
        printf("Order accepted\n");
        printf("Remaining stock = %d\n", stock - quantity);
    } else {
        // المخزون غير كافٍ
        printf("Not enough stock: missing %d units\n", quantity - stock);
    }
    return 0;
}
