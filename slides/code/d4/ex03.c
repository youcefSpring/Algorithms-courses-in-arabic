#include <stdio.h>
#define N 7

int main(void) {
    int temp[N] = {29, 33, 35, 28, 31, 36, 30};
    int i, hot = 0;
    for (i = 0; i < N; i++)
        if (temp[i] > 30)
            hot++;
    printf("Hot days = %d\n", hot);
    return 0;
}
