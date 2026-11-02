#include <stdio.h>

int main(void) {
    char first[40], second[40];
    int pos = 0;
    scanf("%39s %39s", first, second);
    while (first[pos] == second[pos] && first[pos] != '\0')
        pos++;                        // نتقدم ما دام الحرفان متطابقين
    if (first[pos] == second[pos])    // الاثنان '\0'
        printf("Passwords match\n");
    else
        printf("Mismatch at position %d ('%c' vs '%c')\n", pos, first[pos], second[pos]);
    return 0;
}
