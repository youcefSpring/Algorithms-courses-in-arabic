#include <stdio.h>

int search(int T[], int lo, int hi, int x) {
    int mid;
    if (lo > hi)
        return -1;
    mid = (lo + hi) / 2;
    if (T[mid] == x) return mid;
    if (x < T[mid]) return search(T, lo, mid - 1, x);
    return search(T, mid + 1, hi, x);
}

int main(void) {
    int ids[8] = {3, 8, 15, 23, 42, 57, 64, 91};
    printf("42 at index %d\n", search(ids, 0, 7, 42));
    printf("50 at index %d\n", search(ids, 0, 7, 50));
    return 0;
}
