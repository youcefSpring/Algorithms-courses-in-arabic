#include <stdio.h>
#include <string.h>

int main(void) {
    char w[] = "radar";
    int i, n = strlen(w), ok = 1;
    for (i = 0; i < n / 2; i++)
        if (w[i] != w[n - 1 - i])
            ok = 0;
    if (ok)
        printf("%s is a palindrome\n", w);
    else
        printf("%s is not a palindrome\n", w);
    return 0;
}
