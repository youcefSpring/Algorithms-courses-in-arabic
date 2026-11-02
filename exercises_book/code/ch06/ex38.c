#include <stdio.h>

int main(void) {
    char text[] = "This blender is powerful. It crushes ice in seconds! Easy to clean? Yes, very easy.";
    int pos, letters = 0, words = 0, sentences = 0, inWord = 0;
    char ch;
    for (pos = 0; text[pos] != '\0'; pos++) {
        ch = text[pos];
        if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            letters++;
            if (!inWord) { words++; inWord = 1; }    // بداية كلمة
        } else {
            inWord = 0;
        }
        if (ch == '.' || ch == '!' || ch == '?')
            sentences++;                              // نهاية جملة
    }
    printf("Sentences %d, words %d, letters %d\n", sentences, words, letters);
    printf("Words per sentence = %.2f\n", (double)words / sentences);
    printf("Letters per word = %.2f\n", (double)letters / words);
    return 0;
}
