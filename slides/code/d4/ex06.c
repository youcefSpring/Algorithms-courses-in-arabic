#include <stdio.h>
#define N 6

int main(void) {
    int s[N] = {450, 1200, 980, 300, 1500, 760};
    int i, j, t;
    for (i = 0; i < N - 1; i++)
        for (j = 0; j < N - 1 - i; j++)
            if (s[j] < s[j + 1]) {
                t = s[j]; s[j] = s[j + 1]; s[j + 1] = t;
            }
    for (i = 0; i < 3; i++)
        printf("#%d: %d\n", i + 1, s[i]);
    return 0;
}
