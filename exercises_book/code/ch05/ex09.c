#include <stdio.h>

#define NB 4

int main(void) {
    int transfers[NB][NB] = {{30,  5,  2, 0},
                             { 4, 25,  6, 1},
                             { 0,  7, 40, 3},
                             { 2,  1,  5, 18}};
    int depot, from, to, trace = 0, total = 0;
    printf("Diagonal:");
    for (depot = 0; depot < NB; depot++) {
        printf(" %d", transfers[depot][depot]);   // السطر = العمود
        trace += transfers[depot][depot];
    }
    for (from = 0; from < NB; from++)
        for (to = 0; to < NB; to++)
            total += transfers[from][to];
    printf("\nKept = %d, moved = %d\n", trace, total - trace);
    return 0;
}
