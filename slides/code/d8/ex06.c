#include <stdio.h>

int pairs(int month) {
    if (month <= 2)
        return 1;
    return pairs(month - 1) + pairs(month - 2);
}

int main(void) {
    int m;
    for (m = 1; m <= 12; m++)
        printf("%d ", pairs(m));
    printf("\n");
    return 0;
}
