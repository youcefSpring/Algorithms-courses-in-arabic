#include <stdio.h>

int main(void) {
    int items, capacity, boxes, last;
    scanf("%d %d", &items, &capacity);
    // إضافة capacity-1 قبل القسمة تقرب النتيجة إلى الأعلى
    boxes = (items + capacity - 1) / capacity;
    // ما تبقى بعد ملء كل العلب ما عدا الأخيرة
    last = items - (boxes - 1) * capacity;
    printf("Boxes needed = %d\n", boxes);
    printf("Items in last box = %d\n", last);
    return 0;
}
