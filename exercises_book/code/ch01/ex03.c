#include <stdio.h>

int main(void) {
    int r1, r2, r3;               // التقييمات الثلاثة
    double avg;
    scanf("%d %d %d", &r1, &r2, &r3);
    // القسمة على 3.0 تجعل النتيجة حقيقية
    avg = (r1 + r2 + r3) / 3.0;
    printf("Average rating = %.2f / 5\n", avg);
    return 0;
}
