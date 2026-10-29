#include <stdio.h>
#include <string.h>

int main(void) {
    char ref[40] = "CMD-";
    char city[] = "ALG";
    char num[] = "000157";
    strcat(ref, city);
    strcat(ref, "-");
    strcat(ref, num);
    printf("Order: %s\n", ref);
    printf("Length = %lu\n", strlen(ref));
    return 0;
}
