#include <stdio.h>

int countValue(int ratings[], int size, int target) {
    if (size == 0)
        return 0;
    return (ratings[size - 1] == target) + countValue(ratings, size - 1, target);
}

int main(void) {
    int ratings[15] = {5, 4, 5, 3, 5, 2, 4, 5, 1, 4, 5, 3, 4, 5, 4};
    int star;
    for (star = 1; star <= 5; star++)
        printf("%d stars: %d\n", star, countValue(ratings, 15, star));
    return 0;
}
