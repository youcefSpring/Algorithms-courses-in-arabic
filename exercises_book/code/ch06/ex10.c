#include <stdio.h>

int main(void) {
    char email[80];
    int pos, atCount = 0, atPos = -1, dotAfter = 0, length = 0;
    scanf("%79s", email);
    for (pos = 0; email[pos] != '\0'; pos++) {
        if (email[pos] == '@') {
            atCount++;
            atPos = pos;
        } else if (email[pos] == '.' && atPos >= 0 && pos > atPos + 1) {
            dotAfter = 1;             // نقطة في اسم النطاق
        }
        length++;
    }
    if (atCount == 1 && atPos > 0 && dotAfter && email[length - 1] != '.')
        printf("%s: valid\n", email);
    else
        printf("%s: invalid\n", email);
    return 0;
}
