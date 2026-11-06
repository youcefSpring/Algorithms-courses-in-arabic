#include <stdio.h>

#define NB 6
#define PICK 3
#define BUDGET 9000

char names[NB][10] = {"Mouse", "Keyboard", "Headset", "Webcam", "Hub", "Stand"};
int prices[NB] = {1500, 3200, 2800, 4100, 2200, 1900};
int chosen[PICK], valid = 0;

void combine(int start, int picked, int spent) {
    int idx;
    if (spent > BUDGET) return;                   // تقليم
    if (picked == PICK) {
        valid++;
        for (idx = 0; idx < PICK; idx++) printf("%-9s", names[chosen[idx]]);
        printf("= %d\n", spent);
        return;
    }
    for (idx = start; idx < NB; idx++) {
        chosen[picked] = idx;
        combine(idx + 1, picked + 1, spent + prices[idx]);
    }
}

int main(void) {
    combine(0, 0, 0);
    printf("%d bundles within %d DA\n", valid, BUDGET);
    return 0;
}
