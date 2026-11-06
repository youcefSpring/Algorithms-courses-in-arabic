#include <stdio.h>

int main(void) {
    FILE *file = fopen("descriptions.txt", "w");
    int ch, current = 0, line = 0, longest = -1, longestLine = 0, total = 0;
    fprintf(file, "Wireless mouse 2.4 GHz\nMechanical keyboard with blue switches and RGB lighting\n");
    fprintf(file, "USB-C cable 1m\n27 inch 4K IPS monitor, HDR10, 60 Hz, adjustable stand\nHub");
    fclose(file);
    file = fopen("descriptions.txt", "r");
    while (1) {
        ch = fgetc(file);
        if (ch == '\n' || (ch == EOF && current > 0)) {   // نهاية سطر
            line++;
            total += current;
            if (current > longest) { longest = current; longestLine = line; }
            current = 0;
        } else if (ch != EOF) {
            current++;
        }
        if (ch == EOF) break;
    }
    fclose(file);
    printf("%d lines, longest is line %d (%d chars), average %.1f\n",
           line, longestLine, longest, (double)total / line);
    return 0;
}
