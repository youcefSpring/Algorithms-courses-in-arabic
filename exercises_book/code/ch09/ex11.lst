#include <stdio.h>

typedef struct {
    char name[20];
    char category;
    double price;
} Product;

int cheapestOf(Product items[], int size, char category) {
    int idx, best = -1;
    for (idx = 0; idx < size; idx++)
        if (items[idx].category == category &&
            (best < 0 || items[idx].price < items[best].price))
            best = idx;
    return best;
}

int main(void) {
    Product items[8] = {{"Galaxy A", 'P', 38000}, {"ThinkPad", 'L', 95000},
                        {"Charger", 'A', 2200}, {"Redmi 13", 'P', 27500},
                        {"IdeaPad", 'L', 72000}, {"Cable", 'A', 450},
                        {"iPhone", 'P', 165000}, {"Hub", 'A', 3100}};
    char categories[3] = {'P', 'L', 'A'};
    int cat, best;
    for (cat = 0; cat < 3; cat++) {
        best = cheapestOf(items, 8, categories[cat]);
        printf("Category %c: %-9s %9.2f DA\n", categories[cat], items[best].name, items[best].price);
    }
    return 0;
}
