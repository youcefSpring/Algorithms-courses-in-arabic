#include <stdio.h>

typedef struct { char name[16]; double revenue; } Total;

int toInt(const char *text) {
    int value = 0;
    while (*text >= '0' && *text <= '9') value = value * 10 + (*text++ - '0');
    return value;
}

double toDouble(const char *text) {
    double value = 0, scale = 1;
    while (*text >= '0' && *text <= '9') value = value * 10 + (*text++ - '0');
    if (*text == '.') for (text++; *text >= '0' && *text <= '9'; text++) value += (*text - '0') * (scale /= 10);
    return value;
}

int sameText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first == *second;
}

int main(void) {
    FILE *file = fopen("sales.csv", "w");
    char line[100], *fields[4];
    Total totals[10];
    int nbTotals = 0, count, idx, pos, letter;
    fprintf(file, "2026-11-01;Mouse;3;1500\n2026-11-01;Cable;10;450.5\n2026-11-02;Mouse;2;1450\n");
    fprintf(file, "2026-11-02;Monitor;1;32000\n2026-11-03;Cable;4;450.5\n2026-11-03;Mouse;1;1500\n");
    fclose(file);
    file = fopen("sales.csv", "r");
    if (file == NULL) return 1;
    while (fgets(line, 100, file) != NULL) {
        count = 1;
        fields[0] = line;
        for (pos = 0; line[pos] != '\0' && line[pos] != '\n'; pos++)
            if (line[pos] == ';' && count < 4) { line[pos] = '\0'; fields[count++] = line + pos + 1; }
        line[pos] = '\0';
        for (idx = 0; idx < nbTotals && !sameText(totals[idx].name, fields[1]); idx++) {}
        if (idx == nbTotals) {                                   // منتج جديد
            for (letter = 0; (totals[idx].name[letter] = fields[1][letter]) != '\0'; letter++) {}
            totals[idx].revenue = 0;
            nbTotals++;
        }
        totals[idx].revenue += toInt(fields[2]) * toDouble(fields[3]);
    }
    fclose(file);
    for (idx = 0; idx < nbTotals; idx++) printf("%-8s %10.2f DA\n", totals[idx].name, totals[idx].revenue);
    return 0;
}
