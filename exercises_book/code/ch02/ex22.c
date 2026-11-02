#include <stdio.h>

int main(void) {
    long fixedCost, varCost, price, margin, units;
    scanf("%ld %ld %ld", &fixedCost, &varCost, &price);
    margin = price - varCost;                    // ما تربحه في كل وحدة
    if (margin <= 0) {
        printf("Price too low: never profitable\n");
    } else {
        units = fixedCost / margin;                // قسمة صحيحة
        if (fixedCost % margin != 0)
            units = units + 1;            // تقريب إلى الأعلى
        printf("Margin per unit = %ld DA\n", margin);
        printf("Break-even = %ld units\n", units);
    }
    return 0;
}
