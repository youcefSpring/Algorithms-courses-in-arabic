#include <stdio.h>

int main(void) {
    char s[] = "Algorithm";
    int i = 0;
    while (s[i] != '\0') {
        printf("%c ", s[i]);
        i++;
    }
    printf("\nLength = %d\n", i);
    return 0;
}
