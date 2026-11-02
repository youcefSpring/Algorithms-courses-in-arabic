#include <stdio.h>

#define SIZE 5

int main(void) {
    int image[SIZE][SIZE] = {{10, 10,  10, 10, 10},
                             {10, 10, 255, 10, 10},
                             {10, 10,  10, 10, 10},
                             {10, 10,  10,  0, 10},
                             {10, 10,  10, 10, 10}};
    int blurred[SIZE][SIZE], row, col, dRow, dCol, sum;
    for (row = 0; row < SIZE; row++) {
        for (col = 0; col < SIZE; col++) {
            if (row == 0 || col == 0 || row == SIZE - 1 || col == SIZE - 1) {
                blurred[row][col] = image[row][col];   // الحافة دون تغيير
            } else {
                sum = 0;
                for (dRow = -1; dRow <= 1; dRow++)     // الجوار 3×3
                    for (dCol = -1; dCol <= 1; dCol++)
                        sum += image[row + dRow][col + dCol];
                blurred[row][col] = sum / 9;
            }
            printf("%4d", blurred[row][col]);
        }
        printf("\n");
    }
    return 0;
}
