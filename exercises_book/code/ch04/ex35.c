#include <stdio.h>

#define NB 12

int main(void) {
    int items[NB] = {204, 117, 204, 350, 117, 204, 980, 350, 411, 117, 204, 980};
    int index, scan, seen, times, distinct = 0;
    for (index = 0; index < NB; index++) {
        seen = 0;
        for (scan = 0; scan < index && !seen; scan++)
            if (items[scan] == items[index])
                seen = 1;                 // عولج سابقًا
        if (!seen) {
            distinct++;
            times = 0;
            for (scan = index; scan < NB; scan++)
                if (items[scan] == items[index])
                    times++;
            printf("Product %d bought %d time(s)\n", items[index], times);
        }
    }
    printf("Distinct products: %d\n", distinct);
    return 0;
}
