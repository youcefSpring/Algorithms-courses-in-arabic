#include <stdio.h>
#include <string.h>

int pal(char s[], int i, int j) {
    if (i >= j)
        return 1;
    if (s[i] != s[j])
        return 0;
    return pal(s, i + 1, j - 1);
}

int main(void) {
    char a[] = "level", b[] = "algo";
    printf("%s: %d\n", a, pal(a, 0, strlen(a) - 1));
    printf("%s: %d\n", b, pal(b, 0, strlen(b) - 1));
    return 0;
}
