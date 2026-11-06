#include <stdio.h>

typedef struct {
    int id;
    char name[30];
    char city[20];
    int orders;
} Customer;

int main(void) {
    Customer client;
    scanf("%d %29s %19s %d", &client.id, client.name, client.city, &client.orders);
    printf("#%d %s (%s): %d orders -> %s\n", client.id, client.name, client.city,
           client.orders, client.orders > 10 ? "loyal" : "regular");
    return 0;
}
