#include <stdio.h>

long memo[101][101];

long partitions(int total, int largest) {
    if (total == 0) return 1;
    if (total < 0 || largest == 0) return 0;
    if (memo[total][largest] > 0) return memo[total][largest];
    memo[total][largest] = partitions(total - largest, largest)   // دفعة بحجم largest
                         + partitions(total, largest - 1);         // دفعات أصغر فقط
    return memo[total][largest];
}

int main(void) {
    int total, query;
    for (query = 0; query < 3; query++) {
        scanf("%d", &total);
        printf("%d units: %ld ways\n", total, partitions(total, total));
    }
    printf("30 units with batches of at most 5: %ld ways\n", partitions(30, 5));
    return 0;
}
