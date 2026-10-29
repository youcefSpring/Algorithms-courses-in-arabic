#include <stdio.h>

int main(void) {
    char name[20];
    float note, s = 0, n = 0;
    FILE *f = fopen("notes.txt", "w");
    fprintf(f, "Amina 14.5\nYacine 11.25\nSara 16\n");
    fclose(f);
    f = fopen("notes.txt", "r");
    if (f == NULL) return 1;
    while (fscanf(f, "%s %f", name, &note) == 2) {
        printf("%-7s %5.2f\n", name, note);
        s += note; n++;
    }
    fclose(f);
    printf("Average = %.2f\n", s / n);
    return 0;
}
