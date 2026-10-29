#include <stdio.h>
#include <string.h>

int main(void) {
    char plate[] = "12345-121-16";
    int n = strlen(plate);
    int wilaya = (plate[n - 2] - '0') * 10
               + (plate[n - 1] - '0');
    printf("Plate: %s\n", plate);
    printf("Wilaya = %d\n", wilaya);
    return 0;
}
