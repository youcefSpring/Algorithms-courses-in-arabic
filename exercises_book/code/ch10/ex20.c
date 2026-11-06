#include <stdio.h>

typedef struct { char name[12]; double price, rating; } Product;

int byPrice(const Product *first, const Product *second) {
    return first->price < second->price ? -1 : first->price > second->price;
}
int byRating(const Product *first, const Product *second) {
    return first->rating > second->rating ? -1 : first->rating < second->rating;
}
int byName(const Product *first, const Product *second) {
    const char *left = first->name, *right = second->name;
    while (*left != '\0' && *left == *right) { left++; right++; }
    return *left - *right;
}

void sortProducts(Product items[], int size, int (*compare)(const Product *, const Product *)) {
    Product key;
    int idx, back;
    for (idx = 1; idx < size; idx++) {
        key = items[idx];
        for (back = idx - 1; back >= 0 && compare(&key, &items[back]) < 0; back--)
            items[back + 1] = items[back];
        items[back + 1] = key;
    }
}

void show(char label[], Product items[], int size) {
    int idx;
    printf("%-7s", label);
    for (idx = 0; idx < size; idx++) printf(" %s", items[idx].name);
    printf("\n");
}

int main(void) {
    Product items[5] = {{"Monitor", 32000, 4.4}, {"Mouse", 1500, 4.7}, {"Laptop", 89000, 4.2},
                        {"Keyboard", 3200, 4.5}, {"Webcam", 4100, 3.9}};
    sortProducts(items, 5, byPrice);  show("price:", items, 5);
    sortProducts(items, 5, byRating); show("rating:", items, 5);
    sortProducts(items, 5, byName);   show("name:", items, 5);
    return 0;
}
