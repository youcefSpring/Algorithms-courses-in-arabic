#include <stdio.h>

typedef struct {
    char sku[10];
    char name[20];
    double price;
} Product;

int sameText(char first[], char second[]) {
    int pos = 0;
    while (first[pos] != '\0' && first[pos] == second[pos]) pos++;
    return first[pos] == second[pos];          // انتهتا معًا
}

int findBySku(Product items[], int size, char sku[]) {
    int idx;
    for (idx = 0; idx < size; idx++)
        if (sameText(items[idx].sku, sku)) return idx;
    return -1;
}

int main(void) {
    Product items[5] = {{"KB-204", "Keyboard", 3200}, {"MS-110", "Mouse", 1500},
                        {"MN-270", "Monitor", 32000}, {"HD-500", "Headset", 5400},
                        {"CB-001", "Cable", 450}};
    char sku[10];
    int nbQueries, query, idx;
    scanf("%d", &nbQueries);
    for (query = 0; query < nbQueries; query++) {
        scanf("%9s", sku);
        idx = findBySku(items, 5, sku);
        if (idx >= 0) printf("%s: %s, %.2f DA\n", sku, items[idx].name, items[idx].price);
        else printf("%s: unknown SKU\n", sku);
    }
    return 0;
}
