#include <stdio.h>

int main(void) {
    int shelves[3][4] = {{101, 204, 330, 415},
                         {512, 618, 777, 801},
                         {905, 999, 120, 343}};
    int target, aisle, slot, found = 0, foundAisle = 0, foundSlot = 0;
    scanf("%d", &target);
    for (aisle = 0; aisle < 3 && !found; aisle++)         // نخرج من الحلقتين
        for (slot = 0; slot < 4 && !found; slot++)
            if (shelves[aisle][slot] == target) {
                found = 1;
                foundAisle = aisle;
                foundSlot = slot;
            }
    if (found)
        printf("Product %d: aisle %d, slot %d\n", target, foundAisle, foundSlot);
    else
        printf("Product %d not found\n", target);
    return 0;
}
