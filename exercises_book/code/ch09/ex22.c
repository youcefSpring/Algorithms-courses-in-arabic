#include <stdio.h>

typedef struct { int day, month, year; } Date;
typedef struct {
    char code[12];
    int percent;
    Date start, end;
    double minBasket;
} Coupon;

long dateKey(Date date) { return date.year * 10000L + date.month * 100 + date.day; }

int isValid(Coupon coupon, Date today, double basket) {
    long key = dateKey(today);
    return key >= dateKey(coupon.start) && key <= dateKey(coupon.end) && basket >= coupon.minBasket;
}

int main(void) {
    Coupon coupons[4] = {{"WELCOME10", 10, {1, 1, 2026}, {31, 12, 2026}, 0},
                         {"AUTUMN20", 20, {1, 9, 2026}, {31, 10, 2026}, 5000},
                         {"BIG15", 15, {1, 11, 2026}, {30, 11, 2026}, 20000},
                         {"BLACK30", 30, {27, 11, 2026}, {30, 11, 2026}, 10000}};
    Date today = {6, 11, 2026};
    double basket = 24500;
    int idx, best = -1;
    for (idx = 0; idx < 4; idx++) {
        printf("%-10s %s\n", coupons[idx].code, isValid(coupons[idx], today, basket) ? "valid" : "-");
        if (isValid(coupons[idx], today, basket) &&
            (best < 0 || coupons[idx].percent > coupons[best].percent))
            best = idx;
    }
    if (best >= 0)
        printf("Apply %s: %.2f -> %.2f DA\n", coupons[best].code, basket,
               basket * (100 - coupons[best].percent) / 100);
    return 0;
}
