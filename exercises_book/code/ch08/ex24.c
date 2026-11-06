#include <stdio.h>

#define NB 5

int coins[NB] = {5, 10, 20, 50, 100};
long memo[1001][NB];

long ways(int amount, int coinIndex) {
    if (amount == 0) return 1;                       // مبلغ مدفوع بالضبط
    if (amount < 0 || coinIndex == NB) return 0;
    if (memo[amount][coinIndex] >= 0) return memo[amount][coinIndex];
    memo[amount][coinIndex] = ways(amount - coins[coinIndex], coinIndex)   // نستعمل القطعة
                            + ways(amount, coinIndex + 1);                 // ننتقل إلى التالية
    return memo[amount][coinIndex];
}

int main(void) {
    int amount, query, row, col;
    for (row = 0; row <= 1000; row++)
        for (col = 0; col < NB; col++) memo[row][col] = -1;
    for (query = 0; query < 2; query++) {
        scanf("%d", &amount);
        printf("%d DA can be paid in %ld ways\n", amount, ways(amount, 0));
    }
    return 0;
}
