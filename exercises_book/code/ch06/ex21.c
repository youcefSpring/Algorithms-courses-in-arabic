#include <stdio.h>

int main(void) {
    char text[] = "Fast delivery and excellent customer service. Recommended seller!";
    int count[26] = {0}, pos, rank, letter, best;
    char ch;
    for (pos = 0; text[pos] != '\0'; pos++) {
        ch = text[pos];
        if (ch >= 'A' && ch <= 'Z') ch += 'a' - 'A';
        if (ch >= 'a' && ch <= 'z')
            count[ch - 'a']++;                // 'a' -> 0 ... 'z' -> 25
    }
    for (rank = 1; rank <= 5; rank++) {
        best = 0;
        for (letter = 1; letter < 26; letter++)
            if (count[letter] > count[best])
                best = letter;
        printf("%d. '%c': %d\n", rank, 'a' + best, count[best]);
        count[best] = -1;                     // لا نختاره مرة أخرى
    }
    return 0;
}
