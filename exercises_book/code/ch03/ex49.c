#include <stdio.h>

int main(void) {
    long minLevel, maxLevel, seed, stock, pending = 0, demand;
    int day, wait = 0, outdays = 0, orders = 0;
    double hold = 0, shortc = 0, orderc = 0;
    scanf("%ld %ld %ld", &minLevel, &maxLevel, &seed);
    stock = maxLevel;
    for (day = 1; day <= 60; day++) {
        if (pending > 0) {            // طلبية في الطريق
            wait--;
            if (wait == 0) {          // وصلت
                stock += pending;
                pending = 0;
            }
        }
        seed = (seed * 75) % 65537;   // مولد عشوائي يدوي
        demand = seed % 40;                // طلب اليوم 0..39
        if (demand > stock) {              // نفاد: الطلب أكبر من المخزون
            shortc += 50.0 * (demand - stock);
            stock = 0;
            outdays++;
        } else {
            stock -= demand;
        }
        hold += 2.0 * stock;          // تكلفة التخزين اليومية
        if (stock < minLevel && pending == 0) {
            pending = maxLevel - stock;      // نطلب ما يكمل إلى maxLevel
            wait = 2;
            orders++;
            orderc += 500;
        }
    }
    printf("Orders placed: %d\n", orders);
    printf("Stock-out days: %d\n", outdays);
    printf("Holding = %.0f, shortage = %.0f, ordering = %.0f\n", hold, shortc, orderc);
    printf("Total cost = %.0f DA\n", hold + shortc + orderc);
    return 0;
}
