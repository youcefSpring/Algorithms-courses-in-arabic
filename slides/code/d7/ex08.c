#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isStrong(char pw[]) {
    int i, d = 0, u = 0;
    for (i = 0; pw[i] != '\0'; i++) {
        if (isdigit(pw[i])) d = 1;
        if (isupper(pw[i])) u = 1;
    }
    return strlen(pw) >= 8 && d && u;
}

int main(void) {
    printf("%d\n", isStrong("hello"));
    printf("%d\n", isStrong("Hello2026"));
    return 0;
}
