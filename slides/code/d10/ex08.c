#include <stdio.h>

int length(char *s) {
    char *p = s;
    while (*p != '\0')
        p++;
    return p - s;
}

int main(void) {
    char msg[] = "Pointers are powerful";
    printf("Length = %d\n", length(msg));
    return 0;
}
