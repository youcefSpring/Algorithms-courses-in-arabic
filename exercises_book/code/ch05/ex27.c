#include <stdio.h>

int main(void) {
    int sales[3][4] = {{120, 95, 140, 180},
                       { 80, 60,  75,  90},
                       {200, 210, 190, 250}};
    int prefix[4][5] = {{0}};             // سطر وعمود إضافيان من الأصفار
    int row, col, r1, r2, c1, c2;
    for (row = 0; row < 3; row++)
        for (col = 0; col < 4; col++)
            // نطرح التداخل الذي جُمع مرتين
            prefix[row + 1][col + 1] = sales[row][col] + prefix[row][col + 1]
                                     + prefix[row + 1][col] - prefix[row][col];
    scanf("%d %d %d %d", &r1, &r2, &c1, &c2);
    printf("Stores %d-%d, days %d-%d: %d\n", r1, r2, c1 + 1, c2 + 1,
           prefix[r2 + 1][c2 + 1] - prefix[r1][c2 + 1]
           - prefix[r2 + 1][c1] + prefix[r1][c1]);
    return 0;
}
