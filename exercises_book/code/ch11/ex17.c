#include <stdio.h>

#define MAXW 80

int clean(char *word) {
    int read, write = 0;
    for (read = 0; word[read] != '\0'; read++) {
        char ch = word[read];
        if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';
        if (ch >= 'a' && ch <= 'z') word[write++] = ch;    // نبقي الحروف فقط
    }
    word[write] = '\0';
    return write;
}

int sameText(const char *first, const char *second) {
    while (*first != '\0' && *first == *second) { first++; second++; }
    return *first == *second;
}

int main(void) {
    FILE *file = fopen("comments.txt", "w");
    char words[MAXW][20], word[40];
    int counts[MAXW], used[MAXW], nb = 0, idx, rank, best, letter;
    fprintf(file, "Fast delivery! Great quality, great price.\nDelivery was fast and the quality is great.\n");
    fprintf(file, "Price is fair; delivery slow this time. Quality GREAT.\n");
    fclose(file);
    file = fopen("comments.txt", "r");
    if (file == NULL) return 1;
    while (fscanf(file, "%39s", word) == 1) {
        if (clean(word) < 4) continue;                    // كلمات قصيرة
        for (idx = 0; idx < nb && !sameText(words[idx], word); idx++) {}
        if (idx == nb && nb < MAXW) {
            for (letter = 0; (words[nb][letter] = word[letter]) != '\0'; letter++) {}
            counts[nb] = 0;
            used[nb] = 0;
            nb++;
        }
        counts[idx]++;
    }
    fclose(file);
    for (rank = 0; rank < 5 && rank < nb; rank++) {
        best = -1;
        for (idx = 0; idx < nb; idx++)
            if (!used[idx] && (best < 0 || counts[idx] > counts[best])) best = idx;
        used[best] = 1;
        printf("%d. %-9s %d\n", rank + 1, words[best], counts[best]);
    }
    return 0;
}
