#include <stdio.h>

float bill(int kwh) {
    if (kwh <= 125)
        return kwh * 1.78;
    return 125 * 1.78 + (kwh - 125) * 4.18;
}

int main(void) {
    printf("100 kWh: %.2f DA\n", bill(100));
    printf("300 kWh: %.2f DA\n", bill(300));
    return 0;
}
