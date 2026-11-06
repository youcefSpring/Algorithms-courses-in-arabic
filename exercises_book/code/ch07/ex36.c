#include <stdio.h>

double toCelsius(double fahrenheit) {
    return (fahrenheit - 32) * 5 / 9;
}

char status(double celsius) {
    if (celsius < 2) return 'L';          // بارد جدًا
    if (celsius <= 8) return 'O';         // مقبول
    return 'H';                           // ساخن
}

int main(void) {
    double readings[8] = {38.5, 41.0, 44.6, 47.3, 35.1, 39.2, 42.8, 50.0};
    double temp;
    int idx, alarms = 0;
    char code;
    for (idx = 0; idx < 8; idx++) {
        temp = toCelsius(readings[idx]);
        code = status(temp);
        if (code != 'O') alarms++;
        printf("%5.1f F = %5.2f C [%c]\n", readings[idx], temp, code);
    }
    printf("Alarms: %d\n", alarms);
    return 0;
}
