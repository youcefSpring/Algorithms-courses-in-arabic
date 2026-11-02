#include <stdio.h>

#define NB_STATES 3

int main(void) {
    double transition[NB_STATES][NB_STATES] = {{0.0, 0.6, 0.4},   // جديد
                                               {0.0, 0.8, 0.2},   // نشط
                                               {0.0, 0.3, 0.7}};  // خامل
    double current[NB_STATES] = {1000, 0, 0}, next[NB_STATES];
    int months, month, from, to;
    scanf("%d", &months);
    for (month = 1; month <= months; month++) {
        for (to = 0; to < NB_STATES; to++) {
            next[to] = 0;
            for (from = 0; from < NB_STATES; from++)
                next[to] += current[from] * transition[from][to];
        }
        for (to = 0; to < NB_STATES; to++)
            current[to] = next[to];       // الشهر التالي ينطلق من هنا
        printf("Month %d: new %.0f, active %.1f, idle %.1f\n",
               month, current[0], current[1], current[2]);
    }
    return 0;
}
