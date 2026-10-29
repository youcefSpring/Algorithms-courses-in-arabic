#include <stdio.h>

void coupon(float *price, int percent) {
    *price = *price * (100 - percent) / 100;
}

int main(void) {
    float cart[3] = {2500, 12000, 890};
    int i;
    for (i = 0; i < 3; i++) {
        coupon(&cart[i], 10);
        printf("%.2f DA\n", cart[i]);
    }
    return 0;
}
