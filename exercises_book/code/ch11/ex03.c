#include <stdio.h>

int main(void) {
    FILE *file = fopen("orders.log", "w");
    int ch, lines = 0, chars = 0, last = '\n';
    fprintf(file, "2026-11-01 #7781 paid\n2026-11-01 #7782 shipped\n");
    fprintf(file, "2026-11-02 #7783 paid\n2026-11-03 #7784 cancelled");   // دون سطر جديد في النهاية
    fclose(file);
    file = fopen("orders.log", "r");
    if (file == NULL) return 1;
    while ((ch = fgetc(file)) != EOF) {
        chars++;
        if (ch == '\n') lines++;
        last = ch;
    }
    if (last != '\n' && chars > 0) lines++;   // السطر الأخير دون '\n'
    fclose(file);
    printf("%d lines, %d characters\n", lines, chars);
    return 0;
}
