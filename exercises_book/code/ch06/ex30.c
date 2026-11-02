#include <stdio.h>

int main(void) {
    long amount;
    int digits[20], count = 0, pos, write = 0;
    char text[40];
    scanf("%ld", &amount);
    do {
        digits[count++] = amount % 10;    // الأرقام من الآحاد
        amount /= 10;
    } while (amount > 0);
    for (pos = count - 1; pos >= 0; pos--) {
        text[write++] = '0' + digits[pos];
        if (pos > 0 && pos % 3 == 0)      // بقي مضاعف لـ 3 أرقام
            text[write++] = ' ';
    }
    text[write] = '\0';
    printf("%s DA\n", text);
    return 0;
}
