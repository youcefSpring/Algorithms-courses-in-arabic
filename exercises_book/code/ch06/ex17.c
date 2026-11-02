#include <stdio.h>

int main(void) {
    char text[30];
    double value = 0, scale = 1;
    int pos, afterDot = 0, digit;
    scanf("%29s", text);
    for (pos = 0; text[pos] != '\0'; pos++) {
        if (text[pos] == '.') {
            afterDot = 1;
            continue;
        }
        digit = text[pos] - '0';
        if (!afterDot) {
            value = value * 10 + digit;       // الجزء الصحيح
        } else {
            scale /= 10;                      // 0.1 ثم 0.01 ...
            value += digit * scale;
        }
    }
    printf("Price = %.2f, with tax = %.2f\n", value, value * 1.19);
    return 0;
}
