#include <stdio.h>

int main(void) {
    char mail[] = "student@ens.dz";
    int i, at = 0, dot = 0;
    for (i = 0; mail[i] != '\0'; i++) {
        if (mail[i] == '@') at++;
        if (mail[i] == '.' && at == 1) dot = 1;
    }
    if (at == 1 && dot)
        printf("Valid email\n");
    else
        printf("Invalid email\n");
    return 0;
}
