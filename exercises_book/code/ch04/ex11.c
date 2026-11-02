#include <stdio.h>

#define SIZE 7

int main(void) {
    int series[SIZE] = {10, 20, 30, 40, 50, 60, 70};
    int left = 0, right = SIZE - 1, tmp;
    while (left < right) {               // نتوقف عند المنتصف
        tmp = series[left];                 // تبديل الطرفين
        series[left] = series[right];
        series[right] = tmp;
        left++;
        right--;
    }
    for (left = 0; left < SIZE; left++)
        printf("%d ", series[left]);
    printf("\n");
    return 0;
}
