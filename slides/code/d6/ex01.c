#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char pw[] = "Secure2026";
    int i, up = 0, dig = 0;
    for (i = 0; pw[i] != '\0'; i++) {
        if (isupper(pw[i])) up++;
        if (isdigit(pw[i])) dig++;
    }
    printf("Upper = %d, Digits = %d\n", up, dig);
    if (strlen(pw) >= 8 && up > 0 && dig > 0)
        printf("Strong password\n");
    else
        printf("Weak password\n");
    return 0;
}
