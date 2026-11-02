#include <stdio.h>

int main(void) {
    int rating;
    scanf("%d", &rating);
    // && : الشرطان معًا يجب أن يتحققا
    if (rating >= 1 && rating <= 5)
        printf("Rating %d: valid\n", rating);
    else
        printf("Rating %d: invalid (must be 1..5)\n", rating);
    return 0;
}
