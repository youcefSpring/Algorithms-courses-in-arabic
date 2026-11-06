#include <stdio.h>

int getSetting(const char *path, const char *key, char *value) {
    FILE *file = fopen(path, "r");
    char line[100];
    int pos, out;
    if (file == NULL) return 0;
    while (fgets(line, 100, file) != NULL) {
        if (line[0] == '#' || line[0] == '\n') continue;      // تعليق أو فراغ
        for (pos = 0; key[pos] != '\0' && line[pos] == key[pos]; pos++) {}
        if (key[pos] == '\0' && line[pos] == '=') {
            for (pos++, out = 0; line[pos] != '\n' && line[pos] != '\0'; pos++) value[out++] = line[pos];
            value[out] = '\0';
            fclose(file);
            return 1;
        }
    }
    fclose(file);
    return 0;
}

int main(void) {
    FILE *file = fopen("shop.conf", "w");
    const char *keys[4] = {"currency", "vat", "free_shipping", "theme"};
    char value[50];
    int idx;
    fprintf(file, "# TechShop settings\nname=TechShop DZ\ncurrency=DZD\n\nvat=19\n");
    fprintf(file, "# shipping\nfree_shipping=10000\n");
    fclose(file);
    for (idx = 0; idx < 4; idx++) {
        if (getSetting("shop.conf", keys[idx], value))
            printf("%-14s = %s\n", keys[idx], value);
        else
            printf("%-14s = (default) light\n", keys[idx]);
    }
    return 0;
}
