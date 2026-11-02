#include <stdio.h>

#define NB 4

int main(void) {
    int dist[NB][NB] = {{  0,   0,   0, 0},     // الجزائر
                        {430,   0,   0, 0},     // وهران
                        {390, 820,   0, 0},     // قسنطينة
                        {200, 600, 340, 0}};    // سطيف
    int row, col, lower = 1, cityA, cityB, tmp;
    for (row = 0; row < NB; row++)
        for (col = row + 1; col < NB; col++)    // فوق القطر
            if (dist[row][col] != 0)
                lower = 0;
    printf("Lower triangular: %s\n", lower ? "yes" : "no");
    scanf("%d %d", &cityA, &cityB);
    if (cityA < cityB) {                        // نقرأ دائمًا تحت القطر
        tmp = cityA; cityA = cityB; cityB = tmp;
    }
    printf("Distance = %d km\n", dist[cityA][cityB]);
    return 0;
}
