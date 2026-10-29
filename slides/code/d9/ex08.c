#include <stdio.h>
#include <math.h>

typedef struct { char name[15]; float x, y; } City;

float dist(City a, City b) {
    float dx = a.x - b.x, dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main(void) {
    City c1 = {"Boumerdes", 50, 10};
    City c2 = {"Tizi Ouzou", 95, 0};
    printf("%s -> %s\n", c1.name, c2.name);
    printf("%.1f km\n", dist(c1, c2));
    return 0;
}
