#include <stdio.h>

int gcd(int first, int second) {
    int rest;
    while (second != 0) {
        rest = first % second;          // إقليدس
        first = second;
        second = rest;
    }
    return first;
}

int main(void) {
    int pens = 84, notebooks = 120, erasers = 156;
    int boxes = gcd(gcd(pens, notebooks), erasers);   // استدعاء متداخل
    printf("Number of identical boxes: %d\n", boxes);
    printf("Each box: %d pens, %d notebooks, %d erasers\n",
           pens / boxes, notebooks / boxes, erasers / boxes);
    return 0;
}
