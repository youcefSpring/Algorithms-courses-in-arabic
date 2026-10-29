#include <stdio.h>

float average(float a, float b, float c) {
    return (a + b + c) / 3;
}

int main(void) {
    printf("%.2f\n", average(12, 15.5, 9));
    return 0;
}
