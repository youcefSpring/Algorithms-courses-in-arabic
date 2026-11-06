#include <stdio.h>

int splitWords(char *text, char *words[], int maxWords) {
    int count = 0, inWord = 0;
    char *ptr;
    for (ptr = text; *ptr != '\0'; ptr++) {
        if (*ptr == ' ') {
            *ptr = '\0';                       // نهاية الكلمة السابقة
            inWord = 0;
        } else if (!inWord && count < maxWords) {
            words[count++] = ptr;              // عنوان بداية الكلمة
            inWord = 1;
        }
    }
    return count;
}

int main(void) {
    char text[] = "  ergonomic  wireless keyboard with silent keys ";
    char *words[20], *longest;
    int count = splitWords(text, words, 20), idx, len, best = 0;
    longest = words[0];
    for (idx = 0; idx < count; idx++) {
        for (len = 0; words[idx][len] != '\0'; len++) {}
        printf("[%s] ", words[idx]);
        if (len > best) { best = len; longest = words[idx]; }
    }
    printf("\n%d words, longest: %s (%d)\n", count, longest, best);
    return 0;
}
