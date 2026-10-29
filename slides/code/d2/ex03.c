#include <stdio.h>

int main(void) {
    int temp = 43;
    if (temp >= 45)
        printf("Red alert\n");
    else if (temp >= 40)
        printf("Orange alert\n");
    else if (temp >= 35)
        printf("Yellow alert\n");
    else
        printf("Normal\n");
    return 0;
}
