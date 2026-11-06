#include <stdio.h>

#define NBD 30

long tree[NBD + 1];
int operations = 0;

void add(int idx, long delta) {
    for (; idx <= NBD; idx += idx & -idx) { tree[idx] += delta; operations++; }   // نصعد
}

long prefix(int idx) {
    long sum = 0;
    for (; idx > 0; idx -= idx & -idx) { sum += tree[idx]; operations++; }         // نهبط
    return sum;
}

int main(void) {
    long sales[NBD + 1], total;
    int day;
    for (day = 1; day <= NBD; day++) {
        sales[day] = 1000 + (day * 389) % 900;
        add(day, sales[day]);
    }
    printf("build: %d operations\n", operations);
    operations = 0;
    total = prefix(20);                                // نحسب قبل الطباعة
    printf("total days 1-20: %ld (%d ops, naive 20)\n", total, operations);
    operations = 0;
    add(7, -1200);                                     // مرتجع في اليوم 7
    printf("refund on day 7 applied (%d ops)\n", operations);
    operations = 0;
    total = prefix(20) - prefix(10);
    printf("days 11-20: %ld (%d ops, naive 10)\n", total, operations);
    printf("days 1-10 after refund: %ld\n", prefix(10));
    printf("tree[8] covers days 1-8: %ld\n", tree[8]);
    return 0;
}
