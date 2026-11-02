#include <stdio.h>

int main(void) {
    int grid[5][6] = {{1, 1, 0, 1, 1, 1},
                      {1, 1, 1, 1, 1, 0},
                      {1, 1, 1, 1, 1, 1},
                      {0, 1, 1, 1, 1, 1},
                      {1, 1, 1, 1, 0, 1}};
    int myRow, myCol, row, col, dRow, dCol, dist;
    int best = -1, bestRow = -1, bestCol = -1;
    scanf("%d %d", &myRow, &myCol);
    for (row = 0; row < 5; row++)
        for (col = 0; col < 6; col++)
            if (grid[row][col] == 0) {
                dRow = row - myRow; if (dRow < 0) dRow = -dRow;
                dCol = col - myCol; if (dCol < 0) dCol = -dCol;
                dist = dRow + dCol;               // مسافة مانهاتن
                if (best < 0 || dist < best) {
                    best = dist; bestRow = row; bestCol = col;
                }
            }
    printf("Nearest empty shelf: (%d, %d), %d steps\n", bestRow, bestCol, best);
    return 0;
}
