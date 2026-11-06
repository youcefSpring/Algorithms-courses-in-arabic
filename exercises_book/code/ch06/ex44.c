#include <stdio.h>

#define MAXW 60
#define WLEN 16

int main(void) {
    char text[] = "Great phone, great battery! Battery lasts long. "
                  "Screen is great, camera is good. Good price, great value.";
    char words[MAXW][WLEN], word[WLEN], tmpWord[WLEN];
    int counts[MAXW], nbWords = 0, len = 0, pos, idx, found, same, letter, tmpCount, back;
    char ch;
    for (pos = 0; ; pos++) {
        ch = text[pos];
        if (ch >= 'A' && ch <= 'Z') ch = ch - 'A' + 'a';        // حروف صغيرة
        if (ch >= 'a' && ch <= 'z') {
            if (len < WLEN - 1) word[len++] = ch;
        } else if (len > 0) {                                     // نهاية كلمة
            word[len] = '\0';
            found = -1;
            for (idx = 0; idx < nbWords && found < 0; idx++) {
                same = 1;                                         // مقارنة يدوية
                for (letter = 0; word[letter] != '\0' || words[idx][letter] != '\0'; letter++)
                    if (word[letter] != words[idx][letter]) { same = 0; break; }
                if (same) found = idx;
            }
            if (found >= 0) {
                counts[found]++;
            } else if (nbWords < MAXW) {
                for (letter = 0; letter <= len; letter++) words[nbWords][letter] = word[letter];
                counts[nbWords++] = 1;
            }
            len = 0;
        }
        if (text[pos] == '\0') break;
    }
    for (idx = 1; idx < nbWords; idx++) {                         // ترتيب بالإدراج تنازليًا
        tmpCount = counts[idx];
        for (letter = 0; letter < WLEN; letter++) tmpWord[letter] = words[idx][letter];
        back = idx - 1;
        while (back >= 0 && counts[back] < tmpCount) {
            counts[back + 1] = counts[back];
            for (letter = 0; letter < WLEN; letter++) words[back + 1][letter] = words[back][letter];
            back--;
        }
        counts[back + 1] = tmpCount;
        for (letter = 0; letter < WLEN; letter++) words[back + 1][letter] = tmpWord[letter];
    }
    printf("%d distinct words. Top 5:\n", nbWords);
    for (idx = 0; idx < 5 && idx < nbWords; idx++)
        printf("%d. %-8s %d\n", idx + 1, words[idx], counts[idx]);
    return 0;
}
