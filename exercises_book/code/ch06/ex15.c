#include <stdio.h>

int main(void) {
    char text[30];
    int pos = 0, sign = 1, valid = 1;
    long value = 0;
    scanf("%29s", text);
    if (text[0] == '-' || text[0] == '+') {
        if (text[0] == '-') sign = -1;
        pos = 1;
    }
    if (text[pos] == '\0') valid = 0;     // إشارة بلا أرقام
    for (; text[pos] != '\0' && valid; pos++) {
        if (text[pos] >= '0' && text[pos] <= '9')
            value = value * 10 + (text[pos] - '0');   // نزيح ونضيف الرقم
        else
            valid = 0;
    }
    if (valid)
        printf("\"%s\" -> %ld (double: %ld)\n", text, sign * value, 2 * sign * value);
    else
        printf("\"%s\" is not a number\n", text);
    return 0;
}
