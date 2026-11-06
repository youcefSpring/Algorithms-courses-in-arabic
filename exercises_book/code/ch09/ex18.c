#include <stdio.h>

typedef struct {
    long dinars;
    int centimes;
} Money;

long toCentimes(Money amount) { return amount.dinars * 100 + amount.centimes; }

Money fromCentimes(long value) {
    Money amount;
    amount.dinars = value / 100;
    amount.centimes = (int)(value % 100);
    return amount;
}

Money addMoney(Money first, Money second) {
    return fromCentimes(toCentimes(first) + toCentimes(second));
}

Money multiplyMoney(Money amount, int qty) {
    return fromCentimes(toCentimes(amount) * qty);     // حساب بالأعداد الصحيحة
}

void printMoney(Money amount) {
    printf("%ld.%02d DA", amount.dinars, amount.centimes);
}

int main(void) {
    Money prices[3] = {{199, 99}, {1450, 50}, {89, 95}}, total = {0, 0}, line;
    int qty[3] = {7, 3, 11}, idx;
    double check = 0;
    for (idx = 0; idx < 3; idx++) {
        line = multiplyMoney(prices[idx], qty[idx]);
        total = addMoney(total, line);
        printf("%2d x ", qty[idx]); printMoney(prices[idx]);
        printf(" = "); printMoney(line); printf("\n");
        check += (prices[idx].dinars + prices[idx].centimes / 100.0) * qty[idx];
    }
    printf("Total: "); printMoney(total); printf("\n");
    printf("Same total with double: %.17f\n", check);
    return 0;
}
