#include <stdio.h>

int main(void) {
    char color[10], ch;
    int rgb[3], part, digit, half, value;
    double light;
    scanf("%9s", color);
    for (part = 0; part < 3; part++) {
        value = 0;
        for (half = 0; half < 2; half++) {    // رقمان لكل لون
            ch = color[1 + 2 * part + half];
            if (ch >= '0' && ch <= '9')      digit = ch - '0';
            else if (ch >= 'A' && ch <= 'F') digit = ch - 'A' + 10;
            else                             digit = ch - 'a' + 10;
            value = value * 16 + digit;
        }
        rgb[part] = value;
    }
    light = 0.299 * rgb[0] + 0.587 * rgb[1] + 0.114 * rgb[2];
    printf("%s -> R=%d G=%d B=%d\n", color, rgb[0], rgb[1], rgb[2]);
    printf("Brightness %.1f -> use %s text\n", light, light > 128 ? "black" : "white");
    return 0;
}
