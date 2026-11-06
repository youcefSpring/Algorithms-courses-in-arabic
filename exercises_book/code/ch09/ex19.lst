#include <stdio.h>

typedef struct {
    double length, width, height;
} Box;

Box sortDims(Box box) {
    double tmp;
    if (box.length > box.width)  { tmp = box.length; box.length = box.width; box.width = tmp; }
    if (box.width > box.height)  { tmp = box.width; box.width = box.height; box.height = tmp; }
    if (box.length > box.width)  { tmp = box.length; box.length = box.width; box.width = tmp; }
    return box;                    // length <= width <= height
}

double volume(Box box) { return box.length * box.width * box.height; }

int fitsIn(Box item, Box carton) {
    item = sortDims(item);
    carton = sortDims(carton);
    return item.length <= carton.length && item.width <= carton.width && item.height <= carton.height;
}

int main(void) {
    Box cartons[4] = {{30, 20, 10}, {40, 30, 20}, {15, 60, 15}, {50, 40, 40}};
    Box items[3] = {{12, 55, 9}, {35, 18, 25}, {28, 8, 19}};
    int item, carton, best;
    for (item = 0; item < 3; item++) {
        best = -1;
        for (carton = 0; carton < 4; carton++)
            if (fitsIn(items[item], cartons[carton]) &&
                (best < 0 || volume(cartons[carton]) < volume(cartons[best])))
                best = carton;
        printf("Item %d (%.0fx%.0fx%.0f): carton %d (%.0f cm3)\n", item + 1, items[item].length,
               items[item].width, items[item].height, best + 1, volume(cartons[best]));
    }
    return 0;
}
