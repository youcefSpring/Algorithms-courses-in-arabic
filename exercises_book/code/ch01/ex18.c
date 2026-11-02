#include <stdio.h>

int main(void) {
    int money, notes2000, notes1000, notes500, notes200;
    scanf("%d", &money);              // المبلغ بالدينار
    notes2000 = money / 2000; money = money % 2000;   // أوراق 2000 ثم ما تبقى
    notes1000 = money / 1000; money = money % 1000;   // أوراق 1000
    notes500 = money / 500;  money = money % 500;    // أوراق 500
    notes200 = money / 200;  money = money % 200;    // أوراق 200
    printf("2000 DA x %d\n1000 DA x %d\n", notes2000, notes1000);
    printf("500 DA x %d\n200 DA x %d\n", notes500, notes200);
    printf("Coins: %d DA\n", money);  // الباقي قطع نقدية
    return 0;
}
