#include <stdio.h>

void line(int n) {
    int i;
    for (i = 0; i < n; i++)
        printf("*");
    printf("\n");
}

int main(void) {
    line(5);
    line(10);
    return 0;
}
