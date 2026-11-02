#include <stdio.h>

#define NB 8

int main(void) {
    int systemQty[NB]  = {40, 12, 7, 0, 25, 60, 3, 18};
    int countedQty[NB] = {40, 11, 7, 0, 27, 60, 3, 15};
    int index, mismatches = 0;
    for (index = 0; index < NB; index++) {
        if (systemQty[index] != countedQty[index]) {
            printf("Product %d: system %d, counted %d (%+d)\n", index,
                   systemQty[index], countedQty[index],
                   countedQty[index] - systemQty[index]);
            mismatches++;
        }
    }
    if (mismatches == 0)
        printf("Inventories are identical\n");
    else
        printf("%d mismatch(es) to investigate\n", mismatches);
    return 0;
}
