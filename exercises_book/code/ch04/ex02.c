#include <stdio.h>

int main(void) {
    double sales[7] = {120, 95, 140, 180, 160, 210, 75};   // مبيعات 7 أيام
    double sum = 0, avg;
    int day, above = 0;
    for (day = 0; day < 7; day++)
        sum += sales[day];
    avg = sum / 7;
    // مرور ثانٍ: لم يكن المتوسط معروفًا في المرور الأول
    for (day = 0; day < 7; day++)
        if (sales[day] > avg)
            above++;
    printf("Total = %.0f, average = %.2f\n", sum, avg);
    printf("Days above average: %d\n", above);
    return 0;
}
