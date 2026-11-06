#include <stdio.h>
#include <stdlib.h>

int length(const char *text) {
    int len = 0;
    while (text[len] != '\0') len++;
    return len;
}

char upper(char ch) { return (ch >= 'a' && ch <= 'z') ? ch - 'a' + 'A' : ch; }

char *fullName(const char *first, const char *last) {
    int lenF = length(first), lenL = length(last), pos, out = 0;
    char *label = malloc(lenL + 2 + lenF + 1);
    if (label == NULL) return NULL;
    for (pos = 0; pos < lenL; pos++) label[out++] = upper(last[pos]);   // اللقب كبير
    label[out++] = ',';
    label[out++] = ' ';
    for (pos = 0; pos < lenF; pos++) label[out++] = pos == 0 ? upper(first[pos]) : first[pos];
    label[out] = '\0';
    return label;
}

int main(void) {
    char first[30], last[30], *label;
    int idx;
    for (idx = 0; idx < 2; idx++) {
        scanf("%29s %29s", first, last);
        label = fullName(first, last);
        printf("Ship to: %s\n", label);
        free(label);
    }
    return 0;
}
