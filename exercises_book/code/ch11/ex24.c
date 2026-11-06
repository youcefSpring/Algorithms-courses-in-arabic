#include <stdio.h>

#define MAXE 50

void normalize(char *text) {
    for (; *text != '\0'; text++)
        if (*text >= 'A' && *text <= 'Z') *text = *text - 'A' + 'a';
}

int sameText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first == *second;
}

int main(void) {
    FILE *input = fopen("signups.txt", "w"), *output;
    char seen[MAXE][40], email[40];
    int nb = 0, duplicates = 0, idx, letter;
    fprintf(input, "amina@mail.dz\nkarim@shop.dz\nAmina@Mail.dz\nlina@web.dz\nKARIM@shop.dz\n");
    fprintf(input, "omar@mail.dz\namina@mail.dz\n");
    fclose(input);
    input = fopen("signups.txt", "r");
    output = fopen("unique.txt", "w");
    while (fscanf(input, "%39s", email) == 1) {
        normalize(email);
        for (idx = 0; idx < nb && !sameText(seen[idx], email); idx++) {}
        if (idx == nb && nb < MAXE) {                     // أول ظهور
            for (letter = 0; (seen[nb][letter] = email[letter]) != '\0'; letter++) {}
            nb++;
            fprintf(output, "%s\n", email);
        } else {
            duplicates++;
        }
    }
    fclose(input);
    fclose(output);
    printf("%d unique, %d duplicates removed\n", nb, duplicates);
    output = fopen("unique.txt", "r");
    while (fscanf(output, "%39s", email) == 1) printf("  %s\n", email);
    fclose(output);
    return 0;
}
