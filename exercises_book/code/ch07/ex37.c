#include <stdio.h>

double weightedRating(int votes[]) {
    int star, total = 0, weighted = 0;
    for (star = 0; star < 5; star++) {
        weighted += (star + 1) * votes[star];   // وزن كل نجمة
        total += votes[star];
    }
    return total ? (double)weighted / total : 0;
}

void printStars(double rating) {
    int full = (int)rating, pos;
    int half = rating - full >= 0.5;
    for (pos = 0; pos < 5; pos++) {
        if (pos < full) putchar('*');
        else if (pos == full && half) putchar('+');
        else putchar('.');
    }
}

int main(void) {
    int votes[3][5] = {{2, 3, 10, 40, 45}, {20, 15, 10, 5, 2}, {1, 4, 30, 25, 5}};
    char names[3][12] = {"Earbuds", "Cable", "Mouse"};
    double rating;
    int item;
    for (item = 0; item < 3; item++) {
        rating = weightedRating(votes[item]);
        printf("%-8s ", names[item]);
        printStars(rating);
        printf(" %.2f\n", rating);
    }
    return 0;
}
