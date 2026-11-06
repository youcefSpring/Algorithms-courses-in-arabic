#include <stdio.h>

#define NB 12
#define NBK 3

int nearestCenter(double value, double centers[]) {
    int best = 0, idx;
    double dist, bestDist = -1;
    for (idx = 0; idx < NBK; idx++) {
        dist = value > centers[idx] ? value - centers[idx] : centers[idx] - value;
        if (bestDist < 0 || dist < bestDist) { bestDist = dist; best = idx; }
    }
    return best;
}

int assign(double spend[], int groups[], double centers[]) {
    int idx, group, changed = 0;
    for (idx = 0; idx < NB; idx++) {
        group = nearestCenter(spend[idx], centers);
        if (group != groups[idx]) { groups[idx] = group; changed++; }
    }
    return changed;
}

void updateCenters(double spend[], int groups[], double centers[]) {
    double sums[NBK] = {0};
    int counts[NBK] = {0}, idx;
    for (idx = 0; idx < NB; idx++) {
        sums[groups[idx]] += spend[idx];
        counts[groups[idx]]++;
    }
    for (idx = 0; idx < NBK; idx++)
        if (counts[idx] > 0) centers[idx] = sums[idx] / counts[idx];   // المركز = المتوسط
}

int main(void) {
    double spend[NB] = {12, 15, 9, 48, 52, 45, 110, 18, 55, 98, 120, 50};   // بالآلاف
    double centers[NBK] = {9, 50, 120};
    int groups[NB], idx, iteration = 0, changed = 1, group;
    for (idx = 0; idx < NB; idx++) groups[idx] = -1;
    while (changed > 0) {
        changed = assign(spend, groups, centers);
        updateCenters(spend, groups, centers);
        iteration++;
        printf("Iteration %d: %d changed, centers %.1f %.1f %.1f\n",
               iteration, changed, centers[0], centers[1], centers[2]);
    }
    for (group = 0; group < NBK; group++) {
        printf("Group %d:", group);
        for (idx = 0; idx < NB; idx++)
            if (groups[idx] == group) printf(" %.0f", spend[idx]);
        printf("\n");
    }
    return 0;
}
