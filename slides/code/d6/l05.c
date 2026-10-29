#include <stdio.h>
#include <string.h>

int main(void) {
    char a[30], b[] = "World";
    strcpy(a, "Hello ");
    strcat(a, b);
    printf("%s\n", a);
    printf("Length = %lu\n", strlen(a));
    return 0;
}
