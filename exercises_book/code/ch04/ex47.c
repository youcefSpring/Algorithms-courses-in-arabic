#include <stdio.h>

#define NB 6
#define BUDGET 20

int main(void) {
    int cost[NB] = {5, 8, 4, 10, 3, 7};       // بالآلاف
    int gain[NB] = {12, 20, 9, 25, 5, 14};    // العائد المتوقع
    int best[BUDGET + 1] = {0};
    int take[NB * (BUDGET + 1)] = {0};        // جدول قرارات مسطح
    int camp, money;
    for (camp = 0; camp < NB; camp++) {
        // تنازليًا: best[money - cost] ما زال يخص الحملات السابقة
        for (money = BUDGET; money >= cost[camp]; money--) {
            if (best[money - cost[camp]] + gain[camp] > best[money]) {
                best[money] = best[money - cost[camp]] + gain[camp];
                take[camp * (BUDGET + 1) + money] = 1;
            }
        }
    }
    printf("Max gain = %d with budget %d\n", best[BUDGET], BUDGET);
    money = BUDGET;
    printf("Campaigns:");
    for (camp = NB - 1; camp >= 0; camp--) {  // نعيد بناء الاختيار من الآخر
        if (take[camp * (BUDGET + 1) + money]) {
            printf(" #%d(cost %d)", camp, cost[camp]);
            money -= cost[camp];
        }
    }
    printf("\n");
    return 0;
}
