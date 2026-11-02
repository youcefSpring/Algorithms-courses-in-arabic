#include <stdio.h>

int main(void) {
    double prices[3][3] = {{1200, 1500, 1800},    // صغير، متوسط، كبير
                           { 450,  600,  750},
                           {3000, 3600, 4200}};
    double percent;
    int product, size;
    scanf("%lf", &percent);
    for (product = 0; product < 3; product++) {
        for (size = 0; size < 3; size++) {
            prices[product][size] *= 1 - percent / 100;   // التعديل في المكان
            printf("%8.2f", prices[product][size]);
        }
        printf("\n");
    }
    return 0;
}
