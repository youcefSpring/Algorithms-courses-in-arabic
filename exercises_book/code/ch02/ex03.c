#include <stdio.h>

int main(void) {
    int orderId;
    scanf("%d", &orderId);
    if (orderId % 2 == 0)               // باقي القسمة على 2 يساوي 0: زوجي
        printf("Order %d -> warehouse A\n", orderId);
    else
        printf("Order %d -> warehouse B\n", orderId);
    return 0;
}
