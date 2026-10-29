#include <stdio.h>

float bmi(float w, float h) {
    return w / (h * h);
}

void category(float b) {
    if (b < 18.5)    printf("Underweight\n");
    else if (b < 25) printf("Normal\n");
    else             printf("Overweight\n");
}

int main(void) {
    float b = bmi(68, 1.75);
    printf("BMI = %.1f\n", b);
    category(b);
    return 0;
}
