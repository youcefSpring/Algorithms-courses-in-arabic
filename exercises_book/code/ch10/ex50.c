#include <stdio.h>
#include <stdlib.h>

typedef struct { double posX, posY; } Point;

double dist2(Point first, Point second) {
    return (first.posX - second.posX) * (first.posX - second.posX)
         + (first.posY - second.posY) * (first.posY - second.posY);
}

int main(void) {
    int nbPoints, groups, idx, group, best, changed, iterations = 0, *assign, *counts;
    Point *points, *centers, *sums;
    double sse = 0;
    scanf("%d %d", &nbPoints, &groups);
    points = malloc(nbPoints * sizeof(Point));
    assign = malloc(nbPoints * sizeof(int));
    centers = malloc(groups * sizeof(Point));
    sums = malloc(groups * sizeof(Point));
    counts = malloc(groups * sizeof(int));
    for (idx = 0; idx < nbPoints; idx++) { scanf("%lf %lf", &points[idx].posX, &points[idx].posY); assign[idx] = -1; }
    centers[0] = points[0]; centers[1] = points[3]; centers[2] = points[6];   // بداية متباعدة
    do {
        changed = 0;
        for (idx = 0; idx < nbPoints; idx++) {
            best = 0;
            for (group = 1; group < groups; group++)
                if (dist2(points[idx], centers[group]) < dist2(points[idx], centers[best])) best = group;
            if (best != assign[idx]) { assign[idx] = best; changed++; }
        }
        for (group = 0; group < groups; group++) { sums[group].posX = sums[group].posY = 0; counts[group] = 0; }
        for (idx = 0; idx < nbPoints; idx++) {
            sums[assign[idx]].posX += points[idx].posX;
            sums[assign[idx]].posY += points[idx].posY;
            counts[assign[idx]]++;
        }
        for (group = 0; group < groups; group++)
            if (counts[group] > 0) {
                centers[group].posX = sums[group].posX / counts[group];
                centers[group].posY = sums[group].posY / counts[group];
            }
        iterations++;
    } while (changed > 0);
    for (idx = 0; idx < nbPoints; idx++) sse += dist2(points[idx], centers[assign[idx]]);
    printf("Converged in %d iterations\n", iterations);
    for (group = 0; group < groups; group++)
        printf("Zone %d: center (%.2f, %.2f), %d stops\n", group + 1, centers[group].posX,
               centers[group].posY, counts[group]);
    printf("SSE = %.3f\n", sse);
    free(points); free(assign); free(centers); free(sums); free(counts);
    return 0;
}
