#include <stdio.h>

#define MAXD 128
#define MAXL 16

int main(void) {
    char text[] = "ABABABABCABCABCABCABAB";
    char dict[MAXD][MAXL], candidate[MAXL];
    int size = 26, length = 0, pos, code, letter, curLen, found, same, outCodes = 0, currentCode;
    for (code = 0; code < 26; code++) {               // القاموس الابتدائي
        dict[code][0] = (char)('A' + code);
        dict[code][1] = '\0';
    }
    while (text[length] != '\0') length++;
    candidate[0] = text[0];
    curLen = 1;
    currentCode = text[0] - 'A';
    printf("Codes:");
    for (pos = 1; pos <= length; pos++) {
        candidate[curLen] = text[pos];                // current + next
        candidate[curLen + 1] = '\0';
        found = -1;
        for (code = 0; pos < length && code < size && found < 0; code++) {
            same = 1;
            for (letter = 0; letter <= curLen + 1; letter++)
                if (dict[code][letter] != candidate[letter]) { same = 0; break; }
            if (same) found = code;
        }
        if (found >= 0) {
            currentCode = found;                      // نمدد التسلسل
            curLen++;
        } else {
            printf(" %d", currentCode);
            outCodes++;
            if (size < MAXD && curLen + 1 < MAXL) {   // تسلسل جديد في القاموس
                for (letter = 0; letter <= curLen + 1; letter++) dict[size][letter] = candidate[letter];
                size++;
            }
            candidate[0] = text[pos];
            curLen = 1;
            currentCode = text[pos] - 'A';
        }
    }
    printf("\n%d chars -> %d codes, dictionary size %d\n", length, outCodes, size);
    printf("Compression ratio: %.2f\n", (outCodes * 9.0) / (length * 8.0));
    return 0;
}
