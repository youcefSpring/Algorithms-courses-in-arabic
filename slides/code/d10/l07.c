#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n = 5, i;
    int *T = malloc(n * sizeof(int));
    if (T == NULL) return 1;
    for (i = 0; i < n; i++)
        T[i] = i * i;
    for (i = 0; i < n; i++)
        printf("%d ", T[i]);
    printf("\n");
    free(T);
    return 0;
}
