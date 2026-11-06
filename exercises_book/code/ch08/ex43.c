#include <stdio.h>

#define NB 6

int cols[NB], first[NB], solutions = 0;

int safe(int row, int col) {
    int prev, diff;
    for (prev = 0; prev < row; prev++) {
        diff = cols[prev] > col ? cols[prev] - col : col - cols[prev];
        if (cols[prev] == col || diff == row - prev)   // نفس العمود أو القطر
            return 0;
    }
    return 1;
}

void place(int row) {
    int col, idx;
    if (row == NB) {
        if (solutions == 0)
            for (idx = 0; idx < NB; idx++) first[idx] = cols[idx];
        solutions++;
        return;
    }
    for (col = 0; col < NB; col++)
        if (safe(row, col)) {
            cols[row] = col;
            place(row + 1);                            // التراجع تلقائي عند العودة
        }
}

int main(void) {
    int row, col;
    place(0);
    printf("%d solutions. First one:\n", solutions);
    for (row = 0; row < NB; row++) {
        for (col = 0; col < NB; col++) printf(" %c", first[row] == col ? 'K' : '.');
        printf("\n");
    }
    return 0;
}
