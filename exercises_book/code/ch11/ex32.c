#include <stdio.h>

char lower(char ch) { return (ch >= 'A' && ch <= 'Z') ? ch - 'A' + 'a' : ch; }

int containsIgnoreCase(const char *line, const char *word) {
    const char *start, *left, *right;
    for (start = line; *start != '\0'; start++) {
        for (left = start, right = word; *right != '\0' && lower(*left) == lower(*right); left++, right++) {}
        if (*right == '\0') return 1;
    }
    return 0;
}

int main(void) {
    FILE *file = fopen("support.log", "w");
    char word[30], line[120];
    int number = 0, matches = 0;
    fprintf(file, "#101 customer asks about delivery time\n#102 REFUND requested: item broken\n");
    fprintf(file, "#103 password reset\n#104 partial Refund approved for #102\n#105 invoice copy\n");
    fprintf(file, "#106 refunds policy question\n");
    fclose(file);
    scanf("%29s", word);
    file = fopen("support.log", "r");
    while (fgets(line, 120, file) != NULL) {
        number++;
        if (containsIgnoreCase(line, word)) {
            printf("%d: %s", number, line);
            matches++;
        }
    }
    fclose(file);
    printf("%d matching line(s) for \"%s\"\n", matches, word);
    return 0;
}
