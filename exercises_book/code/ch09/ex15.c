#include <stdio.h>

typedef struct { int day, month, year; } Date;
typedef struct { char name[20]; char city[16]; } Customer;
typedef struct {
    int number;
    Customer client;               // هيكل داخل هيكل
    Date date;
    int nbLines;
    double prices[5];
    int qty[5];
} Order;

void printOrder(Order order) {
    double total = 0;
    int idx, pieces = 0;
    for (idx = 0; idx < order.nbLines; idx++) {
        total += order.prices[idx] * order.qty[idx];
        pieces += order.qty[idx];
    }
    printf("Order #%d for %s (%s)\n", order.number, order.client.name, order.client.city);
    printf("Date: %02d/%02d/%d\n", order.date.day, order.date.month, order.date.year);
    printf("%d lines, %d pieces, total %.2f DA\n", order.nbLines, pieces, total);
}

int main(void) {
    Order order = {7781, {"Nadir", "Tlemcen"}, {5, 11, 2026}, 3,
                   {1500, 3200, 450}, {2, 1, 4}};
    printOrder(order);
    return 0;
}
