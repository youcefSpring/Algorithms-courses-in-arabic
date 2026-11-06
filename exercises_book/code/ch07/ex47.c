#include <stdio.h>

double rate(double hour) {
    return 20 + 60 * hour * (24 - hour) / 144;
}

double absValue(double value) { return value < 0 ? -value : value; }

double trapezoid(double start, double end, int steps) {
    double width = (end - start) / steps, sum = (rate(start) + rate(end)) / 2;
    int idx;
    for (idx = 1; idx < steps; idx++) sum += rate(start + idx * width);
    return sum * width;
}

double simpson(double start, double end, int steps) {
    double width = (end - start) / steps, sum = rate(start) + rate(end);
    int idx;
    for (idx = 1; idx < steps; idx++)
        sum += (idx % 2 == 1 ? 4 : 2) * rate(start + idx * width);   // أوزان 4 و 2
    return sum * width / 3;
}

int main(void) {
    int parts[4] = {2, 4, 8, 16}, idx;
    double trap, simp, exact = 1440;
    printf("Exact daily orders: %.1f\n", exact);
    printf("steps  trapezoid   error   simpson   error\n");
    for (idx = 0; idx < 4; idx++) {
        trap = trapezoid(0, 24, parts[idx]);
        simp = simpson(0, 24, parts[idx]);
        printf("%5d %10.3f %7.3f %9.3f %7.3f\n", parts[idx], trap,
               absValue(trap - exact), simp, absValue(simp - exact));
    }
    printf("Orders 18h-22h: %.1f\n", simpson(18, 22, 8));
    return 0;
}
