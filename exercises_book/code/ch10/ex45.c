#include <stdio.h>
#include <stdlib.h>

#define NB 8

typedef struct { char name[12]; double price; int sold; } Product;

double revenue(const Product *item) { return item->price * item->sold; }

void siftDown(Product **view, int root, int size) {
    int child;
    Product *tmp;
    while (2 * root + 1 < size) {
        child = 2 * root + 1;
        if (child + 1 < size && revenue(view[child + 1]) > revenue(view[child])) child++;
        if (revenue(view[root]) >= revenue(view[child])) return;
        tmp = view[root]; view[root] = view[child]; view[child] = tmp;   // ننزل
        root = child;
    }
}

int main(void) {
    Product items[NB] = {{"Phone", 32000, 40}, {"Case", 900, 310}, {"Laptop", 89000, 12},
                         {"Earbuds", 5400, 95}, {"Charger", 2200, 150}, {"Watch", 15000, 28},
                         {"Cable", 450, 600}, {"Tablet", 41000, 18}};
    Product **view = malloc(NB * sizeof(Product *)), *tmp;
    int idx, root, end;
    for (idx = 0; idx < NB; idx++) view[idx] = &items[idx];
    for (root = NB / 2 - 1; root >= 0; root--) siftDown(view, root, NB);   // بناء الكومة
    printf("Top revenue: %s\n", view[0]->name);
    for (end = NB - 1; end > 0; end--) {
        tmp = view[0]; view[0] = view[end]; view[end] = tmp;            // الأكبر إلى النهاية
        siftDown(view, 0, end);
    }
    for (idx = NB - 1; idx >= 0; idx--)
        printf("%-8s %10.0f DA\n", view[idx]->name, revenue(view[idx]));
    free(view);
    return 0;
}
