#include <stdio.h>

int main(void) {
    int r, prev, m = 1;
    FILE *f = fopen("meter.txt", "w");
    fprintf(f, "1200 1385 1590 1742\n");
    fclose(f);
    f = fopen("meter.txt", "r");
    if (f == NULL) return 1;
    fscanf(f, "%d", &prev);
    while (fscanf(f, "%d", &r) == 1) {
        printf("Month %d: %d kWh\n", m++, r - prev);
        prev = r;
    }
    fclose(f);
    return 0;
}
