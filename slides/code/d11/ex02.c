#include <stdio.h>
#include <string.h>

int main(void) {
    char name[20], best[20] = "";
    int score, max = -1;
    FILE *f = fopen("scores.txt", "w");
    fprintf(f, "Riyad 87\nIsmael 92\nAissa 78\n");
    fclose(f);
    f = fopen("scores.txt", "r");
    if (f == NULL) return 1;
    while (fscanf(f, "%s %d", name, &score) == 2)
        if (score > max) { max = score; strcpy(best, name); }
    fclose(f);
    printf("Best: %s (%d)\n", best, max);
    return 0;
}
