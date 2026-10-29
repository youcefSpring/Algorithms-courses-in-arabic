#include <stdio.h>
#define PI 3.14159

int main(void) {
    float r, s;
    printf("Radius: ");
    scanf("%f", &r);
    s = PI * r * r;
    printf("Area = %.2f\n", s);
    return 0;
}
