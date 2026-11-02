#include <stdio.h>

#define NB_ROWS 6
#define NB_FEAT 3

int main(void) {
    double features[NB_ROWS][NB_FEAT] = {{1200, 0.5, 340},
                                         {4500, 2.0,  80},
                                         { 300, 0.2, 900},
                                         {8000, 3.5,  45},
                                         {2500, 1.1, 210},
                                         { 950, 0.8, 500}};
    double colMin, colMax;
    int feat, row;
    for (feat = 0; feat < NB_FEAT; feat++) {          // عمود بعد عمود
        colMin = colMax = features[0][feat];
        for (row = 1; row < NB_ROWS; row++) {
            if (features[row][feat] < colMin) colMin = features[row][feat];
            if (features[row][feat] > colMax) colMax = features[row][feat];
        }
        for (row = 0; row < NB_ROWS; row++)
            features[row][feat] = (features[row][feat] - colMin) / (colMax - colMin);
    }
    printf(" price weight sales\n");
    for (row = 0; row < NB_ROWS; row++)
        printf(" %.2f  %.2f   %.2f\n", features[row][0], features[row][1], features[row][2]);
    return 0;
}
