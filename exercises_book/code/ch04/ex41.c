#include <stdio.h>

#define NB 12

int main(void) {
    int profit[NB] = {-200, 150, 300, -120, 400, -500, 100, 250, -50, 300, -400, 80};
    int current = profit[0], best = profit[0];
    int start = 0, bestFrom = 0, bestTo = 0, day;
    for (day = 1; day < NB; day++) {
        if (current < 0) {        // ماضٍ سالب يضر: نبدأ فترة جديدة
            current = profit[day];
            start = day;
        } else {
            current += profit[day];   // نمدد الفترة الحالية
        }
        if (current > best) {
            best = current;
            bestFrom = start;
            bestTo = day;
        }
    }
    printf("Best period: day %d to day %d, profit = %d DA\n",
           bestFrom + 1, bestTo + 1, best);
    return 0;
}
