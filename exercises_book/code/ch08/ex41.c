#include <stdio.h>

#define NB 10

int buffer[NB];

long sortCount(int values[], int low, int high) {
    int middle, first, second, out, idx;
    long count;
    if (low >= high) return 0;
    middle = (low + high) / 2;
    count = sortCount(values, low, middle) + sortCount(values, middle + 1, high);
    first = low; second = middle + 1; out = low;
    while (first <= middle && second <= high) {
        if (values[first] <= values[second]) {
            buffer[out++] = values[first++];
        } else {
            buffer[out++] = values[second++];
            count += middle - first + 1;          // كل الباقي في اليسار أكبر منه
        }
    }
    while (first <= middle) buffer[out++] = values[first++];
    while (second <= high) buffer[out++] = values[second++];
    for (idx = low; idx <= high; idx++) values[idx] = buffer[idx];
    return count;
}

int main(void) {
    int customer[NB] = {3, 1, 2, 5, 4, 7, 10, 6, 9, 8};   // رتبة المحرك لكل منتج حسب ترتيب الزبون
    int reversed[NB] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    long inv;
    int idx;
    inv = sortCount(customer, 0, NB - 1);
    printf("Inversions: %ld of %d pairs\n", inv, NB * (NB - 1) / 2);
    printf("Kendall tau = %.3f\n", 1 - 4.0 * inv / (NB * (NB - 1)));
    printf("Sorted: ");
    for (idx = 0; idx < NB; idx++) printf("%d ", customer[idx]);
    printf("\nFully reversed list: %ld inversions\n", sortCount(reversed, 0, NB - 1));
    return 0;
}
