#include <stdio.h>

#define NB 4
#define NB_DAYS 3

int main(void) {
    int sales[NB][NB_DAYS] = {{80, 60, 75}, {200, 210, 190}, {120, 95, 140}, {10, 300, 20}};
    int id[NB] = {0, 1, 2, 3}, total[NB];
    int store, day, pos, scan, best, tmp;
    for (store = 0; store < NB; store++) {
        total[store] = 0;
        for (day = 0; day < NB_DAYS; day++)
            total[store] += sales[store][day];
    }
    for (pos = 0; pos < NB - 1; pos++) {          // ترتيب بالانتقاء
        best = pos;
        for (scan = pos + 1; scan < NB; scan++)
            if (total[scan] > total[best])
                best = scan;
        tmp = total[pos]; total[pos] = total[best]; total[best] = tmp;
        tmp = id[pos]; id[pos] = id[best]; id[best] = tmp;
        for (day = 0; day < NB_DAYS; day++) {     // تبديل السطرين كاملين
            tmp = sales[pos][day];
            sales[pos][day] = sales[best][day];
            sales[best][day] = tmp;
        }
    }
    for (store = 0; store < NB; store++) {
        printf("#%d store %d:", store + 1, id[store]);
        for (day = 0; day < NB_DAYS; day++)
            printf(" %3d", sales[store][day]);
        printf(" = %d\n", total[store]);
    }
    return 0;
}
