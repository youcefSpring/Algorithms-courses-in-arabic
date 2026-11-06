#include <stdio.h>
#include <stdlib.h>

int compareText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first - *second;
}

char *copyText(const char *text) {
    int len = 0, pos;
    char *copy;
    while (text[len] != '\0') len++;
    copy = malloc(len + 1);
    for (pos = 0; pos <= len; pos++) copy[pos] = text[pos];
    return copy;
}

void insertSorted(char ***list, int *count, const char *name) {
    char **bigger = malloc((*count + 1) * sizeof(char *));
    int pos = 0, idx;
    while (pos < *count && compareText((*list)[pos], name) < 0) pos++;   // موضع الإدراج
    for (idx = 0; idx < pos; idx++) bigger[idx] = (*list)[idx];
    bigger[pos] = copyText(name);
    for (idx = pos; idx < *count; idx++) bigger[idx + 1] = (*list)[idx];
    free(*list);                          // الجدول القديم (المؤشرات فقط)
    *list = bigger;
    (*count)++;
}

int main(void) {
    char **brands = NULL, name[30];
    int count = 0, nb, idx;
    scanf("%d", &nb);
    for (idx = 0; idx < nb; idx++) {
        scanf("%29s", name);
        insertSorted(&brands, &count, name);
        printf("after %-8s:", name);
        for (int show = 0; show < count; show++) printf(" %s", brands[show]);
        printf("\n");
    }
    for (idx = 0; idx < count; idx++) free(brands[idx]);
    free(brands);
    return 0;
}
