#include <stdio.h>

int main(void) {
    char text[] = "Step on no pets";
    int left = 0, right = 0, ok = 1;
    char chLeft, chRight;
    while (text[right] != '\0')
        right++;
    right--;                              // آخر حرف
    while (left < right && ok) {
        while (text[left] == ' ') left++;     // نتخطى الفراغات
        while (text[right] == ' ') right--;
        chLeft = text[left];
        chRight = text[right];
        if (chLeft >= 'A' && chLeft <= 'Z') chLeft += 'a' - 'A';
        if (chRight >= 'A' && chRight <= 'Z') chRight += 'a' - 'A';
        if (chLeft != chRight)
            ok = 0;
        left++;
        right--;
    }
    printf("\"%s\" is %sa palindrome\n", text, ok ? "" : "not ");
    return 0;
}
