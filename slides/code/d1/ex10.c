#include <stdio.h>

int main(void) {
    int total = 7385;   /* seconds */
    int h = total / 3600;
    int m = (total % 3600) / 60;
    int s = total % 60;
    printf("Duration = %dh %dmin %ds\n", h, m, s);
    return 0;
}
