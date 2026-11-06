#include <stdio.h>

double discountRate(char category) {
    switch (category) {
        case 'B': return 0.05;
        case 'S': return 0.10;
        case 'G': return 0.15;
        default:  return 0.0;            // زبون عادي
    }
}

double finalAmount(double amount, char category) {
    return amount * (1 - discountRate(category)) + 150;
}

int main(void) {
    int nbOrders, order;
    double amount;
    char category;
    scanf("%d", &nbOrders);
    for (order = 0; order < nbOrders; order++) {
        scanf("%lf %c", &amount, &category);
        printf("%8.2f (%c, -%2.0f%%) -> %8.2f DA\n", amount, category,
               discountRate(category) * 100, finalAmount(amount, category));
    }
    return 0;
}
