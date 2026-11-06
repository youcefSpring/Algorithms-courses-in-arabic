#include <stdio.h>

#define CAP 4

typedef struct { double data[CAP]; double *next; int count; } Ring;

void addPrice(Ring *ring, double price) {
    *ring->next = price;
    ring->next++;
    if (ring->next == ring->data + CAP) ring->next = ring->data;   // دوران
    if (ring->count < CAP) ring->count++;
}

double average(const Ring *ring) {
    double sum = 0;
    int idx;
    for (idx = 0; idx < ring->count; idx++) sum += ring->data[idx];
    return sum / ring->count;
}

int main(void) {
    double prices[7] = {32000, 33500, 31000, 34500, 30000, 29000, 31500};
    Ring ring;
    int idx;
    ring.next = ring.data;
    ring.count = 0;
    for (idx = 0; idx < 7; idx++) {
        addPrice(&ring, prices[idx]);
        printf("add %.0f -> last %d avg %.2f\n", prices[idx], ring.count, average(&ring));
    }
    return 0;
}
