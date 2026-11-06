#include <stdio.h>

typedef struct { char name[16]; int visitors, buyers; } Variant;

double mySqrt(double value) {
    double guess = value > 1 ? value : 1;
    int iter;
    for (iter = 0; iter < 60; iter++) guess = (guess + value / guess) / 2;
    return guess;
}

double rate(Variant variant) { return (double)variant.buyers / variant.visitors; }

int main(void) {
    Variant tests[2][2] = {{{"A: old page", 4800, 192}, {"B: new photos", 4750, 238}},
                           {{"A: green btn", 1200, 54}, {"B: red btn", 1180, 59}}};
    double rateA, rateB, pooled, zValue;
    int test;
    for (test = 0; test < 2; test++) {
        rateA = rate(tests[test][0]);
        rateB = rate(tests[test][1]);
        pooled = (double)(tests[test][0].buyers + tests[test][1].buyers)
               / (tests[test][0].visitors + tests[test][1].visitors);
        zValue = (rateB - rateA) / mySqrt(pooled * (1 - pooled) *
                 (1.0 / tests[test][0].visitors + 1.0 / tests[test][1].visitors));
        printf("%s %.2f%% vs %s %.2f%%\n", tests[test][0].name, 100 * rateA,
               tests[test][1].name, 100 * rateB);
        printf("  lift %+.1f%%, z = %.2f -> %s\n", 100 * (rateB - rateA) / rateA, zValue,
               (zValue > 1.96 || zValue < -1.96) ? "significant" : "not significant");
    }
    return 0;
}
