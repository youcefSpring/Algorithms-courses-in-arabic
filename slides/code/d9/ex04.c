#include <stdio.h>

typedef struct { int h, m; } Time;

Time arrival(Time dep, int minutes) {
    Time a;
    int total = dep.h * 60 + dep.m + minutes;
    a.h = (total / 60) % 24;
    a.m = total % 60;
    return a;
}

int main(void) {
    Time dep = {22, 45};
    Time a = arrival(dep, 150);    /* 2h30 */
    printf("Arrival: %02d:%02d\n", a.h, a.m);
    return 0;
}
