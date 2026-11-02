#include <stdio.h>

int main(void) {
    char review[] = "  Great   phone, fast delivery  and good price ";
    int words = 0, inWord = 0, pos;
    for (pos = 0; review[pos] != '\0'; pos++) {
        if (review[pos] == ' ') {
            inWord = 0;               // الفراغ ينهي الكلمة
        } else if (!inWord) {
            words++;                  // أول حرف من كلمة جديدة
            inWord = 1;
        }
    }
    printf("Words: %d\n", words);
    return 0;
}
