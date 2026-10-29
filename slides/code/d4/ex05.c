#include <stdio.h>
#define N 4

int main(void) {
    float price[N] = {2500, 890, 4300, 150};
    int qty[N] = {1, 3, 2, 10};
    float total = 0;
    int i;
    for (i = 0; i < N; i++)
        total += price[i] * qty[i];
    printf("Cart total = %.2f DA\n", total);
    return 0;
}
