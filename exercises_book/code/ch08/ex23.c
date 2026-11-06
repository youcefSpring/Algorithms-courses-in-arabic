#include <stdio.h>

#define NB 4

int dist[NB + 1][NB + 1] = {{0, 12, 18, 9, 22},
                            {12, 0, 7, 14, 11},
                            {18, 7, 0, 10, 6},
                            {9, 14, 10, 0, 15},
                            {22, 11, 6, 15, 0}};
int order[NB] = {1, 2, 3, 4}, bestOrder[NB], bestLength = 100000, tours = 0;

void permute(int depth) {
    int idx, tmp, length;
    if (depth == NB) {                                    // ترتيب كامل
        length = dist[0][order[0]] + dist[order[NB - 1]][0];
        for (idx = 0; idx < NB - 1; idx++) length += dist[order[idx]][order[idx + 1]];
        tours++;
        if (length < bestLength) {
            bestLength = length;
            for (idx = 0; idx < NB; idx++) bestOrder[idx] = order[idx];
        }
        return;
    }
    for (idx = depth; idx < NB; idx++) {
        tmp = order[depth]; order[depth] = order[idx]; order[idx] = tmp;
        permute(depth + 1);
        tmp = order[depth]; order[depth] = order[idx]; order[idx] = tmp;   // تراجع
    }
}

int main(void) {
    int idx;
    permute(0);
    printf("%d tours tested\nBest: 0", tours);
    for (idx = 0; idx < NB; idx++) printf(" -> %d", bestOrder[idx]);
    printf(" -> 0 = %d km\n", bestLength);
    return 0;
}
