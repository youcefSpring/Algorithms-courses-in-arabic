#include <stdio.h>

void addOrder(const char *mode, int number, double amount) {
    FILE *file = fopen("journal.txt", mode);
    if (file == NULL) return;
    fprintf(file, "#%d %.2f\n", number, amount);
    fclose(file);
}

int main(void) {
    FILE *file;
    int ch;
    addOrder("w", 7781, 12500);       // ينشئ الملف من جديد
    addOrder("a", 7782, 3200);        // يضيف في النهاية
    addOrder("a", 7783, 899.5);
    file = fopen("journal.txt", "r");
    if (file == NULL) return 1;
    while ((ch = fgetc(file)) != EOF) putchar(ch);
    fclose(file);
    return 0;
}
