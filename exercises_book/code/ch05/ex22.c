#include <stdio.h>

#define NB 4

int main(void) {
    int together[NB][NB] = {{ 0, 12,  5,  3},
                            {12,  0,  7,  9},
                            { 5,  8,  0,  2},
                            { 3,  9,  2,  0}};
    int row, col, errors = 0;
    for (row = 0; row < NB; row++)
        for (col = row + 1; col < NB; col++)      // نصف المصفوفة يكفي
            if (together[row][col] != together[col][row]) {
                printf("Mismatch (%d,%d): %d vs %d\n", row, col,
                       together[row][col], together[col][row]);
                errors++;
            }
    if (errors == 0)
        printf("Matrix is symmetric\n");
    else
        printf("%d error(s) found\n", errors);
    return 0;
}
