#include <stdio.h>

int main(void) {
    int timestamp, hours, minutes, seconds;
    scanf("%d", &timestamp);              // ثوانٍ منذ منتصف الليل
    hours = timestamp / 3600;                 // 3600 ثانية في الساعة
    minutes = (timestamp % 3600) / 60;          // ما تبقى من الساعة بالدقائق
    seconds = timestamp % 60;                   // الثواني المتبقية
    printf("%d s -> %02d:%02d:%02d\n", timestamp, hours, minutes, seconds);
    return 0;
}
