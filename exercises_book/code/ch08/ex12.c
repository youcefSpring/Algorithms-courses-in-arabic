#include <stdio.h>

int search(double prices[], int low, int high, double target) {
    int middle;
    if (low > high) return -1;                  // مجال فارغ
    middle = (low + high) / 2;
    printf("  [%d..%d] middle %d\n", low, high, middle);
    if (prices[middle] == target) return middle;
    if (prices[middle] < target)
        return search(prices, middle + 1, high, target);
    return search(prices, low, middle - 1, target);
}

int main(void) {
    double prices[12] = {99, 450, 560, 650, 899, 1200, 1500, 2300, 3200, 4100, 7800, 12500};
    double target;
    int query, idx;
    for (query = 0; query < 2; query++) {
        scanf("%lf", &target);
        printf("Search %.0f:\n", target);
        idx = search(prices, 0, 11, target);
        if (idx >= 0) printf("  found at index %d\n", idx);
        else printf("  not found\n");
    }
    return 0;
}
