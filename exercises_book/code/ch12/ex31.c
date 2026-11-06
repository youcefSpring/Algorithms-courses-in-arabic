#include <stdio.h>
#include <stdlib.h>

typedef struct Item { char name[12]; double price; struct Item *next; } Item;
typedef struct Category { char name[12]; Item *items; struct Category *next; } Category;

void copyText(char *target, const char *source) { while ((*target++ = *source++) != '\0') {} }

int sameText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first == *second;
}

Category *getCategory(Category **list, const char *name) {
    Category **link = list;
    while (*link != NULL && !sameText((*link)->name, name)) link = &(*link)->next;
    if (*link == NULL) {                                  // قسم جديد في النهاية
        *link = malloc(sizeof(Category));
        copyText((*link)->name, name);
        (*link)->items = NULL;
        (*link)->next = NULL;
    }
    return *link;
}

void addProduct(Category **list, const char *category, const char *name, double price) {
    Category *cat = getCategory(list, category);
    Item *item = malloc(sizeof(Item));
    copyText(item->name, name);
    item->price = price;
    item->next = cat->items;                              // في رأس قائمة القسم
    cat->items = item;
}

int main(void) {
    const char *cats[7] = {"Phones", "Audio", "Phones", "Laptops", "Audio", "Phones", "Laptops"};
    const char *names[7] = {"Galaxy A", "Earbuds", "Redmi 13", "ThinkPad", "Speaker", "iPhone", "IdeaPad"};
    double prices[7] = {38000, 5400, 27500, 95000, 6800, 165000, 72000}, total;
    Category *categories = NULL, *cat, *nextCat;
    Item *item, *nextItem;
    int idx;
    for (idx = 0; idx < 7; idx++) addProduct(&categories, cats[idx], names[idx], prices[idx]);
    for (cat = categories; cat != NULL; cat = cat->next) {
        printf("%s:", cat->name);
        for (total = 0, item = cat->items; item != NULL; item = item->next) {
            printf(" %s", item->name);
            total += item->price;
        }
        printf("  (total %.0f)\n", total);
    }
    for (cat = categories; cat != NULL; cat = nextCat) {
        for (item = cat->items; item != NULL; item = nextItem) { nextItem = item->next; free(item); }
        nextCat = cat->next;
        free(cat);
    }
    return 0;
}
