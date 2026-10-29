#include <stdio.h>

int main(void) {
    int day, t, hot = 0, i;
    int temp[5] = {29, 34, 36, 31, 28};
    FILE *f = fopen("week.csv", "w");
    if (f == NULL) return 1;
    for (i = 0; i < 5; i++)
        fprintf(f, "%d,%d\n", i + 1, temp[i]);
    fclose(f);
    f = fopen("week.csv", "r");
    while (fscanf(f, "%d,%d", &day, &t) == 2)
        if (t > 30) hot++;
    fclose(f);
    printf("Hot days = %d\n", hot);
    return 0;
}
