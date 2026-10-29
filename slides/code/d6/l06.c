#include <stdio.h>
#include <string.h>

int main(void) {
    char pass[] = "algo2026";
    char input[] = "algo2026";
    if (strcmp(pass, input) == 0)
        printf("Access granted\n");
    else
        printf("Access denied\n");
    printf("%d\n", strcmp("abc", "abd") < 0);
    return 0;
}
