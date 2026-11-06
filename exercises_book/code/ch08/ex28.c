#include <stdio.h>

#define NB 7

int prices[NB] = {1200, 3500, 899, 2100, 650, 1750, 4100};
int taken[NB];

int canSpend(int index, int remaining) {
    if (remaining == 0) return 1;                     // صرفنا البطاقة بالضبط
    if (index == NB || remaining < 0) return 0;
    taken[index] = 1;
    if (canSpend(index + 1, remaining - prices[index])) return 1;   // نأخذ المنتج
    taken[index] = 0;
    return canSpend(index + 1, remaining);                          // لا نأخذه
}

int main(void) {
    int card, query, idx;
    for (query = 0; query < 2; query++) {
        scanf("%d", &card);
        for (idx = 0; idx < NB; idx++) taken[idx] = 0;
        printf("Card %d DA: ", card);
        if (canSpend(0, card)) {
            for (idx = 0; idx < NB; idx++)
                if (taken[idx]) printf("%d ", prices[idx]);
            printf("\n");
        } else {
            printf("impossible\n");
        }
    }
    return 0;
}
