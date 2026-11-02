#include <stdio.h>

int main(void) {
    int products[10] = {101, 205, 330, 412, 560, 618};
    int size = 6, removedId, index, pos = -1;
    scanf("%d", &removedId);
    for (index = 0; index < size; index++)           // البحث عن الموضع
        if (products[index] == removedId) { pos = index; break; }
    if (pos == -1) {
        printf("%d not found\n", removedId);
    } else {
        for (index = pos; index < size - 1; index++)
            products[index] = products[index + 1];          // نسد الفراغ
        size--;                          // الجدول فقد عنصرًا
        for (index = 0; index < size; index++)
            printf("%d ", products[index]);
        printf("\n");
    }
    return 0;
}
