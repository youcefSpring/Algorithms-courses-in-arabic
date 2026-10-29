#include <stdio.h>

int main(void) {
    FILE *f = fopen("notes.txt", "w");
    if (f == NULL) return 1;
    fprintf(f, "Amina 14.5\n");
    fprintf(f, "Yacine 11.25\n");
    fprintf(f, "Sara 16\n");
    fclose(f);
    printf("File written\n");
    return 0;
}
