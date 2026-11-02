#include <stdio.h>

int main(void) {
    int hour, minute, delay, total, ah, am;
    scanf("%d %d %d", &hour, &minute, &delay);
    total = hour * 60 + minute + delay;       // الدقائق منذ منتصف الليل
    ah = (total / 60) % 24;       // % 24 تعيد الساعة بعد 23 إلى 0
    am = total % 60;              // الدقائق
    printf("Arrival time: %02d:%02d\n", ah, am);
    return 0;
}
