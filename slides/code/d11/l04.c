#include <stdio.h>

int main(void) {
    char line[100];
    int n = 0;
    FILE *f = fopen("todo.txt", "w");
    fprintf(f, "Revise pointers\nWrite report\nSport\n");
    fclose(f);
    f = fopen("todo.txt", "r");
    if (f == NULL) return 1;
    while (fgets(line, 100, f) != NULL)
        printf("%d. %s", ++n, line);
    fclose(f);
    return 0;
}
