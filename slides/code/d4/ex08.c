#include <stdio.h>
#define N 5

int main(void) {
    int min[N] = {95, 40, 130, 25, 60};   /* per app */
    int i, total = 0, top = 0;
    for (i = 0; i < N; i++) {
        total += min[i];
        if (min[i] > min[top])
            top = i;
    }
    printf("Screen time = %dh %dmin\n",
           total / 60, total % 60);
    printf("Most used app = %d\n", top + 1);
    return 0;
}
