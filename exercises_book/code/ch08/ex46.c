#include <stdio.h>

#define NB 14

int prices[NB] = {520, 480, 510, 530, 470, 545, 560, 500, 575, 590, 540, 600, 580, 620};
int memo[NB], nextOf[NB];

int lisFrom(int idx) {
    int next, len, best = 1;
    if (memo[idx] > 0) return memo[idx];
    nextOf[idx] = -1;
    for (next = idx + 1; next < NB; next++)
        if (prices[next] > prices[idx]) {
            len = 1 + lisFrom(next);
            if (len > best) { best = len; nextOf[idx] = next; }
        }
    memo[idx] = best;
    return best;
}

int main(void) {
    int idx, best = 0, start = 0, len;
    for (idx = 0; idx < NB; idx++) {
        len = lisFrom(idx);
        if (len > best) { best = len; start = idx; }
    }
    printf("Longest rising trend: %d weeks\n", best);
    for (idx = start; idx != -1; idx = nextOf[idx])     // إعادة البناء
        printf("w%d:%d ", idx + 1, prices[idx]);
    printf("\n");
    return 0;
}
