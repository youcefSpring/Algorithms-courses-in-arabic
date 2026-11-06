#include <stdio.h>

#define NBC 5
#define NBP 4
#define NBO 10

typedef struct { int id; char name[10]; char city[10]; } Customer;
typedef struct { int id; char name[10]; double price; } Product;
typedef struct { int customerId, productId, qty; } Order;
typedef struct { char city[10]; double total; int orders; } CityTotal;

Customer customers[NBC] = {{1, "Amina", "Oran"}, {2, "Karim", "Algiers"}, {3, "Lina", "Oran"},
                           {4, "Omar", "Setif"}, {5, "Sara", "Algiers"}};
Product products[NBP] = {{10, "Phone", 32000}, {11, "Case", 900}, {12, "Earbuds", 5400}, {13, "Laptop", 89000}};
Order orders[NBO] = {{1, 10, 1}, {2, 11, 3}, {3, 12, 2}, {4, 13, 1}, {5, 10, 2},
                     {1, 12, 1}, {2, 13, 1}, {3, 11, 5}, {4, 11, 2}, {5, 12, 1}};

int findCustomer(int id) {
    int idx;
    for (idx = 0; idx < NBC; idx++) if (customers[idx].id == id) return idx;
    return -1;
}

int findProduct(int id) {
    int idx;
    for (idx = 0; idx < NBP; idx++) if (products[idx].id == id) return idx;
    return -1;
}

int sameText(char first[], char second[]) {
    int pos = 0;
    while (first[pos] != '\0' && first[pos] == second[pos]) pos++;
    return first[pos] == second[pos];
}

int main(void) {
    CityTotal report[NBC], tmp;
    int nbCities = 0, idx, client, item, pos, letter, pass;
    for (idx = 0; idx < NBO; idx++) {
        client = findCustomer(orders[idx].customerId);       // ربط مع الزبائن
        item = findProduct(orders[idx].productId);           // ربط مع المنتجات
        for (pos = 0; pos < nbCities && !sameText(report[pos].city, customers[client].city); pos++) {}
        if (pos == nbCities) {                               // GROUP BY city
            for (letter = 0; letter < 10; letter++) report[pos].city[letter] = customers[client].city[letter];
            report[pos].total = 0;
            report[pos].orders = 0;
            nbCities++;
        }
        report[pos].total += orders[idx].qty * products[item].price;
        report[pos].orders++;
    }
    for (pass = 0; pass < nbCities - 1; pass++)              // ORDER BY total DESC
        for (idx = 0; idx < nbCities - 1 - pass; idx++)
            if (report[idx].total < report[idx + 1].total) {
                tmp = report[idx]; report[idx] = report[idx + 1]; report[idx + 1] = tmp;
            }
    printf("city      orders      total\n");
    for (idx = 0; idx < nbCities; idx++)
        printf("%-9s %6d %10.0f\n", report[idx].city, report[idx].orders, report[idx].total);
    return 0;
}
