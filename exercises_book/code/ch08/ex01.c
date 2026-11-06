#include <stdio.h>

long factorial(int count) {
    if (count <= 1)
        return 1;                          // الحالة الأساسية
    return count * factorial(count - 1);   // الاستدعاء العودي
}

int main(void) {
    int count, idx;
    scanf("%d", &count);
    for (idx = 1; idx <= count; idx++)
        printf("%d products: %ld arrangements\n", idx, factorial(idx));
    return 0;
}
