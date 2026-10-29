#include <stdio.h>
#define N 5

int main(void) {
    int T[N] = {12, 7, 9, 15, 3};
    int i, x, found = 0;
    printf("Value: ");
    scanf("%d", &x);
    for (i = 0; i < N && !found; i++) {
        if (T[i] == x) found = 1;
    }
    if (found) printf("Found at index %d\n", i - 1);
    else       printf("Not found\n");
    return 0;
}
