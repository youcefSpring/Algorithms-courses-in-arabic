#include <stdio.h>

typedef struct { float x, y; } Point;

Point middle(Point a, Point b) {
    Point m;
    m.x = (a.x + b.x) / 2;
    m.y = (a.y + b.y) / 2;
    return m;
}

int main(void) {
    Point a = {0, 0}, b = {4, 6};
    Point m = middle(a, b);
    printf("Middle = (%.1f, %.1f)\n", m.x, m.y);
    return 0;
}
