#include <stdio.h>

int sameText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first == *second;
}

int main(void) {
    FILE *file = fopen("hits.log", "w");
    char visitors[30][20], ip[20], page[40];
    int hits[30], nb = 0, idx, top = 0, total = 0, letter;
    fprintf(file, "41.200.3.7 /home\n105.98.1.20 /phones\n41.200.3.7 /phones\n197.112.5.9 /home\n");
    fprintf(file, "41.200.3.7 /cart\n105.98.1.20 /cart\n41.200.3.7 /checkout\n154.121.0.4 /home\n");
    fclose(file);
    file = fopen("hits.log", "r");
    while (fscanf(file, "%19s %39s", ip, page) == 2) {
        for (idx = 0; idx < nb && !sameText(visitors[idx], ip); idx++) {}
        if (idx == nb) {                                    // زائر جديد
            for (letter = 0; (visitors[nb][letter] = ip[letter]) != '\0'; letter++) {}
            hits[nb++] = 0;
        }
        hits[idx]++;
        total++;
    }
    fclose(file);
    for (idx = 0; idx < nb; idx++) {
        printf("%-12s %d hits\n", visitors[idx], hits[idx]);
        if (hits[idx] > hits[top]) top = idx;
    }
    printf("%d hits from %d unique visitors; most active %s\n", total, nb, visitors[top]);
    return 0;
}
