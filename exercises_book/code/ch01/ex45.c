#include <stdio.h>

int main(void) {
    long totalSec, rest, days, hours, minutes, seconds, visitors, avg;
    scanf("%ld %ld", &totalSec, &visitors);     // الثواني الكلية، عدد الزوار
    days = totalSec / 86400;  rest = totalSec % 86400; // 86400 ثانية في اليوم
    hours = rest / 3600;   rest = rest % 3600;  // الساعات من الباقي
    minutes = rest / 60;     seconds = rest % 60;    // الدقائق والثواني
    avg = totalSec / visitors;                   // متوسط الزائر بالثواني
    printf("Total: %ld d %ld h %ld min %ld s\n", days, hours, minutes, seconds);
    printf("Per visitor: %ld min %ld s\n", avg / 60, avg % 60);
    return 0;
}
