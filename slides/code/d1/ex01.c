#include <stdio.h>

int main(void) {
    float weight = 72.5;   /* kg */
    float height = 1.78;   /* m */
    float bmi = weight / (height * height);
    printf("BMI = %.1f\n", bmi);
    return 0;
}
