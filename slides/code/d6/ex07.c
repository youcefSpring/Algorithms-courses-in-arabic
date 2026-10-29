#include <stdio.h>

int main(void) {
    char s[] = "AI models read text word by word";
    int i, words = 0, inWord = 0;
    for (i = 0; s[i] != '\0'; i++) {
        if (s[i] != ' ' && !inWord) {
            words++;
            inWord = 1;
        } else if (s[i] == ' ') {
            inWord = 0;
        }
    }
    printf("Words = %d\n", words);
    return 0;
}
