#include <stdio.h>

int main(void) {
    double electronics, clothing, books, total, pe, pc, pb;
    scanf("%lf %lf %lf", &electronics, &clothing, &books);
    total = electronics + clothing + books;                // رقم الأعمال الكلي
    pe = electronics / total * 100;             // حصة الإلكترونيات
    pc = clothing / total * 100;             // حصة الملابس
    pb = books / total * 100;             // حصة الكتب
    printf("Electronics: %.1f %%\n", pe);
    printf("Clothing:    %.1f %%\n", pc);
    printf("Books:       %.1f %%\n", pb);
    printf("Check sum:   %.1f %%\n", pe + pc + pb);
    return 0;
}
