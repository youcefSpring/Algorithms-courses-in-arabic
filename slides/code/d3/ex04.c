#include <stdio.h>

int main(void) {
    float sales = 200000;   /* DA, month 1 */
    int month = 1;
    while (sales < 500000) {
        sales = sales * 1.10;   /* +10 % */
        month++;
    }
    printf("Target reached in month %d\n", month);
    printf("Sales = %.0f DA\n", sales);
    return 0;
}
