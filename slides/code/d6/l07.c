#include <stdio.h>
#include <ctype.h>

int main(void) {
    char s[] = "Hello World 2026";
    int i, digits = 0;
    for (i = 0; s[i] != '\0'; i++) {
        s[i] = toupper(s[i]);
        if (isdigit(s[i])) digits++;
    }
    printf("%s\n", s);
    printf("Digits = %d\n", digits);
    return 0;
}
