#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int days = 30, day, nbQueries, query, from, to;
    long *sales = malloc(days * sizeof(long)), *prefix = malloc((days + 1) * sizeof(long));
    long *in, *out;
    for (day = 0; day < days; day++) sales[day] = 1000 + (day * 37) % 500;   // بيانات تجريبية
    prefix[0] = 0;
    for (in = sales, out = prefix; in < sales + days; in++, out++)
        *(out + 1) = *out + *in;                     // المجموع التراكمي
    scanf("%d", &nbQueries);
    for (query = 0; query < nbQueries; query++) {
        scanf("%d %d", &from, &to);
        printf("Days %2d..%2d: %ld DA\n", from, to, prefix[to] - prefix[from - 1]);
    }
    free(sales);
    free(prefix);
    return 0;
}
