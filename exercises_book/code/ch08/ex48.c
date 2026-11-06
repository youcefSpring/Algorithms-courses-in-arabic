#include <stdio.h>

#define NB 12

double xs[NB] = {2, 15, 7, 31, 22, 9, 40, 18, 27, 4, 35, 12};
double ys[NB] = {3, 8, 14, 5, 19, 2, 11, 25, 9, 20, 16, 13};
int pairA, pairB;

double dist2(int first, int second) {
    return (xs[first] - xs[second]) * (xs[first] - xs[second])
         + (ys[first] - ys[second]) * (ys[first] - ys[second]);
}

double check(int first, int second, double best) {
    double value = dist2(first, second);
    if (value < best) { pairA = first; pairB = second; return value; }
    return best;
}

double closest(int low, int high) {
    double best = 1e18, right, gap;
    int first, second, middle;
    if (high - low < 3) {                                   // حالة أساسية صغيرة
        for (first = low; first <= high; first++)
            for (second = first + 1; second <= high; second++)
                best = check(first, second, best);
        return best;
    }
    middle = (low + high) / 2;
    best = closest(low, middle);
    right = closest(middle + 1, high);
    if (right < best) best = right;
    for (first = low; first <= high; first++) {             // الشريط حول خط القسمة
        gap = xs[first] - xs[middle];
        if (gap * gap >= best) continue;
        for (second = first + 1; second <= high; second++) {
            gap = xs[second] - xs[middle];
            if (gap * gap < best) best = check(first, second, best);
        }
    }
    return best;
}

double mySqrt(double value) {
    double guess = value > 1 ? value : 1;
    int iter;
    for (iter = 0; iter < 50; iter++) guess = (guess + value / guess) / 2;
    return guess;
}

int main(void) {
    int idx, back;
    double keyX, keyY, best;
    for (idx = 1; idx < NB; idx++) {                        // ترتيب حسب x
        keyX = xs[idx]; keyY = ys[idx]; back = idx - 1;
        while (back >= 0 && xs[back] > keyX) {
            xs[back + 1] = xs[back]; ys[back + 1] = ys[back]; back--;
        }
        xs[back + 1] = keyX; ys[back + 1] = keyY;
    }
    best = closest(0, NB - 1);
    printf("Closest warehouses: (%.0f,%.0f) and (%.0f,%.0f)\n",
           xs[pairA], ys[pairA], xs[pairB], ys[pairB]);
    printf("Distance: %.3f km\n", mySqrt(best));
    return 0;
}
