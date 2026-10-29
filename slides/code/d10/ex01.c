#include <stdio.h>

int update(float *temp, float newValue) {
    *temp = newValue;
    return *temp > 38;
}

int main(void) {
    float t = 37.1;
    if (update(&t, 38.6))
        printf("Fever alert: %.1f\n", t);
    return 0;
}
