#include <stdio.h>

int main(void) {
    int c, lines = 0, words = 0;
    FILE *f = fopen("posts.txt", "w");
    fputs("Great exam today\nNew course on C\n", f);
    fputs("See you soon\n", f);
    fclose(f);
    f = fopen("posts.txt", "r");
    if (f == NULL) return 1;
    while ((c = fgetc(f)) != EOF) {
        if (c == ' ') words++;
        if (c == '\n') { lines++; words++; }
    }
    fclose(f);
    printf("%d posts, %d words\n", lines, words);
    return 0;
}
