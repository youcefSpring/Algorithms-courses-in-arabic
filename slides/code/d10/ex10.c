#include <stdio.h>

void analyse(int kw[], int n, int *total, int *peak) {
    int i;
    *total = 0;
    *peak = 0;
    for (i = 0; i < n; i++) {
        *total += kw[i];
        if (kw[i] > kw[*peak]) *peak = i;
    }
}

int main(void) {
    int kw[6] = {3, 5, 9, 12, 7, 4}, t, p;
    analyse(kw, 6, &t, &p);
    printf("Total = %d kWh\nPeak at hour %d\n", t, p);
    return 0;
}
