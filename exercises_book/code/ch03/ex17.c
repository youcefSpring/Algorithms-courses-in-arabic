#include <stdio.h>

int main(void) {
    int cycleA, cycleB, gcdA, gcdB, rest, lcm;
    scanf("%d %d", &cycleA, &cycleB);
    gcdA = cycleA; gcdB = cycleB;                 // نسختان لكي لا نفقد cycleA و cycleB
    while (gcdB != 0) {
        rest = gcdA % gcdB;
        gcdA = gcdB;
        gcdB = rest;
    }                             // gcdA = pgcd(cycleA, cycleB)
    lcm = cycleA / gcdA * cycleB;
    printf("Both restocked again after %d days\n", lcm);
    return 0;
}
