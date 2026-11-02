#include <stdio.h>

#define NB_REC 12

int main(void) {
    int category[NB_REC] = {0, 1, 0, 2, 1, 1, 0, 2, 2, 0, 1, 2};
    int month[NB_REC]    = {0, 0, 1, 1, 2, 0, 3, 3, 0, 2, 3, 2};
    int amount[NB_REC]   = {500, 300, 450, 900, 120, 220, 610, 400, 350, 200, 180, 700};
    int pivot[3][4] = {{0}}, colTotal[4] = {0};
    int rec, cat, mon, rowTotal;
    for (rec = 0; rec < NB_REC; rec++)
        pivot[category[rec]][month[rec]] += amount[rec];   // التجميع
    printf("cat |  M1   M2   M3   M4 | total\n");
    for (cat = 0; cat < 3; cat++) {
        rowTotal = 0;
        printf("%3d |", cat);
        for (mon = 0; mon < 4; mon++) {
            printf(" %4d", pivot[cat][mon]);
            rowTotal += pivot[cat][mon];
            colTotal[mon] += pivot[cat][mon];
        }
        printf(" | %5d\n", rowTotal);
    }
    printf("sum |");
    for (mon = 0; mon < 4; mon++)
        printf(" %4d", colTotal[mon]);
    printf("\n");
    return 0;
}
