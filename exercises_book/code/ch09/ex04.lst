#include <stdio.h>

typedef struct {
    double posX, posY;
} Point;

double absValue(double value) { return value < 0 ? -value : value; }

double manhattan(Point first, Point second) {
    return absValue(first.posX - second.posX) + absValue(first.posY - second.posY);
}

int main(void) {
    Point shop = {4, 3};
    Point clients[3] = {{1, 7}, {9, 2}, {4, 10}};
    int idx;
    for (idx = 0; idx < 3; idx++)
        printf("Client %d at (%.0f,%.0f): %.0f km\n", idx + 1,
               clients[idx].posX, clients[idx].posY, manhattan(shop, clients[idx]));
    return 0;
}
