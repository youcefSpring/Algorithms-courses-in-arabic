#include <stdio.h>

int main(void) {
    int c1, c2, c3, c4, c5, nbReviews, weighted;
    double avg;
    scanf("%d %d %d %d %d", &c1, &c2, &c3, &c4, &c5);
    nbReviews = c1 + c2 + c3 + c4 + c5;                   // عدد التقييمات
    weighted = 1 * c1 + 2 * c2 + 3 * c3 + 4 * c4 + 5 * c5; // كل نجمة × عددها
    avg = (double)weighted / nbReviews;                          // متوسط موزون
    printf("Reviews = %d\n", nbReviews);
    printf("Weighted average = %.2f stars\n", avg);
    return 0;
}
