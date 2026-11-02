#include <stdio.h>

int main(void) {
    int orders[100], nbOrders, index;
    scanf("%d", &nbOrders);
    for (index = 0; index < nbOrders; index++)
        scanf("%d", &orders[index]);
    printf("Latest first:");
    for (index = nbOrders - 1; index >= 0; index--)  // من الفهرس الأخير إلى 0
        printf(" %d", orders[index]);
    printf("\n");
    return 0;
}
