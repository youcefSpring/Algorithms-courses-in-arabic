#include <stdio.h>

int main(void) {
    int levels, row, col;
    scanf("%d", &levels);
    for (row = 1; row <= levels; row++) {
        for (col = 1; col <= levels - row; col++)      // فراغات للتوسيط
            printf(" ");
        for (col = 1; col <= 2 * row - 1; col++)  // عدد فردي من النجوم
            printf("*");
        printf("  level %d\n", levels - row + 1);
    }
    return 0;
}
