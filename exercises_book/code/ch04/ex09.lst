#include <stdio.h>

#define NB_REVIEWS 12

int main(void) {
    int ratings[NB_REVIEWS] = {5, 4, 3, 5, 2, 4, 4, 1, 5, 3, 4, 5};
    int index, pos = 0;
    for (index = 0; index < NB_REVIEWS; index++)
        if (ratings[index] >= 4)
            pos++;
    printf("Positive reviews: %d / %d = %.1f %%\n", pos, NB_REVIEWS, pos * 100.0 / NB_REVIEWS);
    return 0;
}
