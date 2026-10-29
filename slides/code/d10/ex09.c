#include <stdio.h>

typedef struct { char id[10]; int speed; } Vehicle;

Vehicle *fastest(Vehicle v[], int n) {
    Vehicle *best = &v[0];
    int i;
    for (i = 1; i < n; i++)
        if (v[i].speed > best->speed)
            best = &v[i];
    return best;
}
int main(void) {
    Vehicle v[3] = {{"B-12", 70}, {"T-04", 160}, {"C-77", 120}};
    Vehicle *f = fastest(v, 3);
    printf("%s: %d km/h\n", f->id, f->speed);
    return 0;
}
