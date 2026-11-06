#include <stdio.h>

#define MAXW 60
#define MAXP 12

char words[MAXW][16];
int lists[MAXW][MAXP], sizes[MAXW], nbWords = 0;

int lookup(const char *word, int add) {
    int idx, pos;
    for (idx = 0; idx < nbWords; idx++) {
        for (pos = 0; word[pos] != '\0' && word[pos] == words[idx][pos]; pos++) {}
        if (word[pos] == words[idx][pos]) return idx;
    }
    if (!add) return -1;
    for (pos = 0; (words[nbWords][pos] = word[pos]) != '\0'; pos++) {}
    sizes[nbWords] = 0;
    return nbWords++;
}

int intersect(const int *first, int sizeA, const int *second, int sizeB, int *out) {
    int left = 0, right = 0, count = 0;
    while (left < sizeA && right < sizeB) {
        if (first[left] == second[right]) { out[count++] = first[left]; left++; right++; }
        else if (first[left] < second[right]) left++;           // نتقدم بالأصغر
        else right++;
    }
    return count;
}

int main(void) {
    FILE *file = fopen("catalog.txt", "w");
    const char *queries[3][3] = {{"wireless", "mouse", ""}, {"usb", "c", "fast"}, {"gaming", "", ""}};
    char word[16];
    int id, idx, ch, pos, query, term, result[MAXP], tmp[MAXP], count;
    fprintf(file, "1: Wireless optical mouse\n2: Gaming mouse RGB wired\n3: USB C fast charger\n");
    fprintf(file, "4: Wireless keyboard and mouse combo\n5: USB C hub fast ethernet\n6: Gaming keyboard wireless\n");
    fclose(file);
    file = fopen("catalog.txt", "r");
    while (fscanf(file, "%d:", &id) == 1) {
        while ((ch = fgetc(file)) != '\n' && ch != EOF) {
            if (ch == ' ') continue;
            pos = 0;
            while (ch != ' ' && ch != '\n' && ch != EOF) {
                if (pos < 15) word[pos++] = (char)(ch >= 'A' && ch <= 'Z' ? ch - 'A' + 'a' : ch);
                ch = fgetc(file);
            }
            word[pos] = '\0';
            idx = lookup(word, 1);
            if (sizes[idx] == 0 || lists[idx][sizes[idx] - 1] != id) lists[idx][sizes[idx]++] = id;
            if (ch == '\n' || ch == EOF) break;
        }
    }
    fclose(file);
    file = fopen("index.txt", "w");
    for (idx = 0; idx < nbWords; idx++) {
        fprintf(file, "%s:", words[idx]);
        for (pos = 0; pos < sizes[idx]; pos++) fprintf(file, " %d", lists[idx][pos]);
        fprintf(file, "\n");
    }
    fclose(file);
    printf("index.txt: %d words\n", nbWords);
    for (query = 0; query < 3; query++) {
        idx = lookup(queries[query][0], 0);
        count = idx >= 0 ? sizes[idx] : 0;
        for (pos = 0; pos < count; pos++) result[pos] = lists[idx][pos];
        for (term = 1; term < 3 && queries[query][term][0] != '\0'; term++) {
            idx = lookup(queries[query][term], 0);
            count = idx >= 0 ? intersect(result, count, lists[idx], sizes[idx], tmp) : 0;
            for (pos = 0; pos < count; pos++) result[pos] = tmp[pos];
        }
        printf("\"%s", queries[query][0]);
        for (term = 1; term < 3 && queries[query][term][0] != '\0'; term++) printf(" %s", queries[query][term]);
        printf("\" ->");
        for (pos = 0; pos < count; pos++) printf(" #%d", result[pos]);
        printf("\n");
    }
    return 0;
}
