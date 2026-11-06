#include <stdio.h>

int main(void) {
    FILE *file = fopen("temps.txt", "w");
    double readings[9] = {4.2, 3.8, 5.1, 6.9, 4.4, 2.7, 3.3, 5.6, 4.0}, value, sum = 0, low = 0, high = 0;
    int idx, count = 0;
    for (idx = 0; idx < 9; idx++) fprintf(file, "%.1f\n", readings[idx]);
    fclose(file);
    file = fopen("temps.txt", "r");
    if (file == NULL) return 1;
    while (fscanf(file, "%lf", &value) == 1) {
        if (count == 0 || value < low) low = value;
        if (count == 0 || value > high) high = value;
        sum += value;
        count++;
    }
    fclose(file);
    printf("%d readings, mean %.2f C, min %.1f, max %.1f\n", count, sum / count, low, high);
    return 0;
}
