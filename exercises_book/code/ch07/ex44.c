#include <stdio.h>

#define NB 6
#define BUDGET 50

int knapsack(int costs[], int gains[], int size, int budget, int chosen[]) {
    int best[NB + 1][BUDGET + 1], item, money, withItem;
    for (money = 0; money <= budget; money++) best[0][money] = 0;
    for (item = 1; item <= size; item++)
        for (money = 0; money <= budget; money++) {
            best[item][money] = best[item - 1][money];             // لا نأخذه
            if (costs[item - 1] <= money) {
                withItem = gains[item - 1] + best[item - 1][money - costs[item - 1]];
                if (withItem > best[item][money]) best[item][money] = withItem;
            }
        }
    money = budget;
    for (item = size; item >= 1; item--) {                         // إعادة البناء
        chosen[item - 1] = best[item][money] != best[item - 1][money];
        if (chosen[item - 1]) money -= costs[item - 1];
    }
    return best[size][budget];
}

int main(void) {
    char names[NB][12] = {"Phone", "Laptop", "Earbuds", "Watch", "Tablet", "Speaker"};
    int costs[NB] = {20, 30, 10, 15, 25, 5};       // بالآلاف
    int gains[NB] = {60, 90, 35, 40, 70, 18};
    int chosen[NB], idx, spent = 0;
    int total = knapsack(costs, gains, NB, BUDGET, chosen);
    for (idx = 0; idx < NB; idx++)
        if (chosen[idx]) {
            printf("Promote %-8s cost %2d gain %2d\n", names[idx], costs[idx], gains[idx]);
            spent += costs[idx];
        }
    printf("Budget used %d/%d, expected gain %d (thousand DA)\n", spent, BUDGET, total);
    return 0;
}
