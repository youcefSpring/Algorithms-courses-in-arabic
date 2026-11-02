#include <stdio.h>

int main(void) {
    char name[] = "Wireless Headphones";  // المترجم يضيف '\0' في النهاية
    int length = 0;
    while (name[length] != '\0')          // نتوقف عند علامة النهاية
        length++;
    printf("\"%s\" has %d characters\n", name, length);
    return 0;
}
