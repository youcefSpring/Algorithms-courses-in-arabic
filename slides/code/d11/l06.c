#include <stdio.h>

int main(void) {
    int c, chars = 0, lines = 0;
    FILE *f = fopen("text.txt", "w");
    fputs("Files keep data.\nEven after exit.\n", f);
    fclose(f);
    f = fopen("text.txt", "r");
    if (f == NULL) return 1;
    while ((c = fgetc(f)) != EOF) {
        chars++;
        if (c == '\n') lines++;
    }
    fclose(f);
    printf("%d chars, %d lines\n", chars, lines);
    return 0;
}
