#include <stdio.h>

int main(void) {
    float bmi = 27.3;
    if (bmi < 18.5)
        printf("Underweight\n");
    else if (bmi < 25)
        printf("Normal\n");
    else if (bmi < 30)
        printf("Overweight\n");
    else
        printf("Obesity\n");
    return 0;
}
