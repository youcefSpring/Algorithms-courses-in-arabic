#include <stdio.h>

int main(void) {
    float t[5] = {37.1, 37.8, 38.4, 38.0, 37.3}, v, s = 0;
    int i, n = 0;
    FILE *f = fopen("temp.txt", "w");
    if (f == NULL) return 1;
    for (i = 0; i < 5; i++) fprintf(f, "%.1f\n", t[i]);
    fclose(f);
    f = fopen("temp.txt", "r");
    if (f == NULL) return 1;
    while (fscanf(f, "%f", &v) == 1) { s += v; n++; }
    fclose(f);
    printf("Readings = %d\nMean = %.2f C\n", n, s / n);
    return 0;
}
