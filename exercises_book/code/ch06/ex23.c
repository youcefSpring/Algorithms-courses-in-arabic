#include <stdio.h>

int main(void) {
    char code[30];
    int shift, pos, round, step;
    scanf("%29s %d", code, &shift);
    for (round = 0; round < 2; round++) {
        // الجولة 0: تشفير، الجولة 1: فك التشفير
        step = (round == 0) ? shift : 26 - shift % 26;
        for (pos = 0; code[pos] != '\0'; pos++) {
            if (code[pos] >= 'A' && code[pos] <= 'Z')
                code[pos] = 'A' + (code[pos] - 'A' + step) % 26;   // دوران
            else if (code[pos] >= '0' && code[pos] <= '9')
                code[pos] = '0' + (code[pos] - '0' + (round == 0 ? shift : 10 - shift % 10)) % 10;
        }
        printf("%s: %s\n", round == 0 ? "Encrypted" : "Decrypted", code);
    }
    return 0;
}
