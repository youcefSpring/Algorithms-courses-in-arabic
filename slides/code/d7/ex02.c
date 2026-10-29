#include <stdio.h>

int points(int scored, int conceded) {
    if (scored > conceded) return 3;
    if (scored == conceded) return 1;
    return 0;
}

int main(void) {
    int total = points(2, 0) + points(1, 1)
              + points(0, 3) + points(4, 2);
    printf("Total points = %d\n", total);
    return 0;
}
