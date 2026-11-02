#include <stdio.h>

int main(void) {
    double avg, rounded;
    int halves, full, half;
    scanf("%lf", &avg);
    halves = (int)(avg * 2 + 0.5);     // عدد أنصاف النجوم بعد التقريب
    full = halves / 2;                 // النجوم الكاملة
    half = halves % 2;                 // 1 إذا بقي نصف نجمة
    rounded = halves / 2.0;                  // القيمة المقربة
    printf("%.2f -> %d full star(s)", avg, full);
    if (half == 1)
        printf(" + half star");
    printf(" (%.1f)\n", rounded);
    if (rounded >= 4.5)       printf("Excellent\n");
    else if (rounded >= 3.5)  printf("Good\n");
    else if (rounded >= 2.5)  printf("Average\n");
    else                printf("Poor\n");
    return 0;
}
