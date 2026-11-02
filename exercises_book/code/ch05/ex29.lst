#include <stdio.h>

int main(void) {
    int image[6][8] = {{ 10,  12, 200, 210,  50,  52, 90,  94},
                       { 14,  16, 205, 215,  54,  56, 92,  96},
                       {100, 104,  30,  34, 250, 246, 10,  12},
                       {102, 106,  32,  36, 248, 252, 14,  16},
                       { 60,  60,  60,  60, 120, 124, 180, 184},
                       { 60,  60,  60,  60, 128, 132, 188, 192}};
    int thumb[3][4], row, col;
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 4; col++) {
            thumb[row][col] = (image[2 * row][2 * col] + image[2 * row][2 * col + 1]
                             + image[2 * row + 1][2 * col] + image[2 * row + 1][2 * col + 1]) / 4;
            printf("%4d", thumb[row][col]);
        }
        printf("\n");
    }
    return 0;
}
