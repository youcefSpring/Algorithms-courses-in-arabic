#include <stdio.h>
#define C 3
#define D 5
int main(void) {
    int t[C][D] = {{31, 33, 35, 34, 32},
                   {24, 26, 25, 27, 28},
                   {38, 41, 43, 40, 39}};
    int i, j, mi = 0, mj = 0;
    for (i = 0; i < C; i++)
        for (j = 0; j < D; j++)
            if (t[i][j] > t[mi][mj]) { mi = i; mj = j; }
    printf("Max = %d C\n", t[mi][mj]);
    printf("City %d, day %d\n", mi + 1, mj + 1);
    return 0;
}
