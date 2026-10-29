#include <stdio.h>

typedef struct { float x, y; } Point;

void show(Point p) {
    printf("(%.1f, %.1f)\n", p.x, p.y);
}

int main(void) {
    Point a = {2, 3.5};
    show(a);
    return 0;
}
