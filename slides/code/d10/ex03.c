#include <stdio.h>

void toFahrenheit(float *t, int n) {
    int i;
    for (i = 0; i < n; i++, t++)
        *t = *t * 9 / 5 + 32;
}

int main(void) {
    float temp[4] = {0, 25, 30, 40};
    int i;
    toFahrenheit(temp, 4);
    for (i = 0; i < 4; i++)
        printf("%.0f ", temp[i]);
    printf("\n");
    return 0;
}
