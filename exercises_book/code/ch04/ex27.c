#include <stdio.h>

#define NB 8

int main(void) {
    double ages[NB] = {22, 35, 41, 28, 19, 55, 33, 47};
    double standard[NB], mean = 0, variance = 0, std, check = 0;
    int index, step;
    for (index = 0; index < NB; index++)
        mean += ages[index];
    mean /= NB;
    for (index = 0; index < NB; index++)
        variance += (ages[index] - mean) * (ages[index] - mean);
    variance /= NB;
    std = variance;                       // الجذر بطريقة نيوتن
    for (step = 0; step < 30; step++)
        std = (std + variance / std) / 2;
    for (index = 0; index < NB; index++) {
        standard[index] = (ages[index] - mean) / std;
        check += standard[index];
        printf("%4.0f -> %+.3f\n", ages[index], standard[index]);
    }
    printf("mean = %.2f, std = %.3f, new mean = %.6f\n", mean, std, check / NB);
    return 0;
}
