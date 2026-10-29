#include <stdio.h>

int main(void) {
    int length = 10, digits = 2, upper = 0;
    if (length >= 8 && digits > 0 && upper > 0)
        printf("Strong password\n");
    else if (length >= 8 || digits > 0)
        printf("Medium password\n");
    else
        printf("Weak password\n");
    return 0;
}
