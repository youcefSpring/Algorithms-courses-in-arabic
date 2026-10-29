#include <stdio.h>

int main(void) {
    int level = 7, hp = 64, l2, h2;
    FILE *f = fopen("save.dat", "w");
    if (f == NULL) return 1;
    fprintf(f, "%d %d\n", level, hp);
    fclose(f);
    f = fopen("save.dat", "r");          /* next session */
    if (f == NULL) return 1;
    fscanf(f, "%d %d", &l2, &h2);
    fclose(f);
    printf("Loaded: level %d, %d HP\n", l2, h2);
    return 0;
}
