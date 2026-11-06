#include <stdio.h>

int isPalindrome(char text[], int left, int right) {
    if (left >= right) return 1;                     // انتهت المقارنات
    if (text[left] != text[right]) return 0;
    return isPalindrome(text, left + 1, right - 1);  // الجزء الداخلي
}

int main(void) {
    char codes[4][20] = {"AB12321BA", "XY-77-YX", "RADAR", "SKU2026"};
    int idx, length;
    for (idx = 0; idx < 4; idx++) {
        length = 0;
        while (codes[idx][length] != '\0') length++;
        printf("%-10s %s\n", codes[idx],
               isPalindrome(codes[idx], 0, length - 1) ? "palindrome" : "no");
    }
    return 0;
}
