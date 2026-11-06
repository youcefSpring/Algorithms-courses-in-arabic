#include <stdio.h>

typedef struct {
    char author[16];
    int stars;
    int verified;
} Review;

int main(void) {
    Review reviews[6] = {{"Karim", 5, 1}, {"Lina", 1, 0}, {"Yacine", 4, 1},
                         {"Sara", 1, 0}, {"Nadir", 4, 1}, {"Meriem", 5, 1}};
    int idx, sumAll = 0, sumVerified = 0, nbVerified = 0;
    for (idx = 0; idx < 6; idx++) {
        sumAll += reviews[idx].stars;
        if (reviews[idx].verified) {             // شراء موثق فقط
            sumVerified += reviews[idx].stars;
            nbVerified++;
        }
    }
    printf("All reviews:      %.2f\n", sumAll / 6.0);
    printf("Verified reviews: %.2f (%d reviews)\n", (double)sumVerified / nbVerified, nbVerified);
    return 0;
}
