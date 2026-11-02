#include <stdio.h>

int main(void) {
    int wilaya, zone, price;
    scanf("%d", &wilaya);
    if (wilaya < 1 || wilaya > 58) {
        printf("Invalid wilaya code\n");
    } else {
        // الحالات الخاصة أولًا، ثم المجالات العامة
        if (wilaya == 16) {
            zone = 0; price = 300;
        } else if (wilaya == 9 || wilaya == 35 || wilaya == 42) {
            zone = 1; price = 500;
        } else if (wilaya <= 30) {
            zone = 2; price = 700;
        } else {
            zone = 3; price = 900;
        }
        printf("Wilaya %d: zone %d, %d DA\n", wilaya, zone, price);
    }
    return 0;
}
