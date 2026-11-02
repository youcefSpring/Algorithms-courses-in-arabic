#include <stdio.h>

int main(void) {
    char user[50];
    int length = 0, pos;
    scanf("%49s", user);              // 49 حرفًا كحد أقصى + '\0'
    while (user[length] != '\0')
        length++;
    for (pos = length - 1; pos >= 0; pos--)
        putchar(user[pos]);           // نطبع حرفًا واحدًا
    putchar('\n');
    return 0;
}
