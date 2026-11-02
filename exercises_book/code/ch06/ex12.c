#include <stdio.h>

int main(void) {
    char text[] = "Ultra thin waterproof smartwatch with heart monitor";
    int pos, current = 0, best = 0, bestStart = 0, words = 0, total = 0, done = 0;
    for (pos = 0; !done; pos++) {
        if (text[pos] == ' ' || text[pos] == '\0') {  // نهاية كلمة
            if (current > best) {
                best = current;
                bestStart = pos - current;
            }
            if (current > 0) { words++; total += current; }
            current = 0;
            if (text[pos] == '\0') done = 1;
        } else {
            current++;
        }
    }
    printf("Longest word: ");
    for (pos = bestStart; pos < bestStart + best; pos++)
        putchar(text[pos]);
    printf(" (%d letters, starts at %d)\n", best, bestStart);
    printf("Average word length: %.2f\n", (double)total / words);
    return 0;
}
