#include <stdio.h>

int main(void) {
    double cart, dl, dc, disc, net, ship;
    int level, coupon, wilaya;
    scanf("%lf %d %d %d", &cart, &level, &coupon, &wilaya);
    switch (level) {                      // تخفيض الوفاء
        case 1:  dl = cart * 0.03; break; // فضي
        case 2:  dl = cart * 0.07; break; // ذهبي
        default: dl = 0;
    }
    dc = 0;                               // تخفيض القسيمة
    if (coupon == 1)
        dc = cart * 0.10;
    else if (coupon == 2 && cart > 8000)
        dc = 1000;
    disc = dl + dc;
    if (disc > 0.3 * cart)                // سقف التخفيضات 30%
        disc = 0.3 * cart;
    net = (cart - disc) * 1.19;           // الرسم بعد التخفيض
    if (level == 2 || net > 10000)
        ship = 0;
    else if (wilaya == 16)
        ship = 300;
    else
        ship = 700;
    printf("Discounts = %.2f DA\n", disc);
    printf("Net with tax = %.2f DA\n", net);
    printf("Shipping = %.2f DA\n", ship);
    printf("TOTAL = %.2f DA\n", net + ship);
    return 0;
}
