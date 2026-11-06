#include <stdio.h>
#include <stdlib.h>

typedef struct { char name[12]; double price, rating; } Product;

Product *filterAbove(const Product *items, int size, double minRating, int *outCount) {
    Product *result;
    int idx, count = 0;
    for (idx = 0; idx < size; idx++) if (items[idx].rating >= minRating) count++;
    *outCount = count;
    if (count == 0) return NULL;
    result = malloc(count * sizeof(Product));      // الحجم المضبوط
    if (result == NULL) { *outCount = 0; return NULL; }
    count = 0;
    for (idx = 0; idx < size; idx++)
        if (items[idx].rating >= minRating) result[count++] = items[idx];
    return result;
}

int main(void) {
    Product items[6] = {{"Monitor", 32000, 4.4}, {"Mouse", 1500, 4.7}, {"Laptop", 89000, 4.2},
                        {"Keyboard", 3200, 4.5}, {"Webcam", 4100, 3.9}, {"Hub", 3100, 4.3}};
    int count, idx;
    Product *best = filterAbove(items, 6, 4.3, &count);
    printf("%d products rated >= 4.3:\n", count);
    for (idx = 0; idx < count; idx++)
        printf("  %-9s %.1f  %8.2f DA\n", best[idx].name, best[idx].rating, best[idx].price);
    free(best);
    return 0;
}
