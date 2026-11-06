#include <stdio.h>

void reverseInPlace(char text[], int left, int right) {
    char tmp;
    if (left >= right) return;
    tmp = text[left];                 // تبديل الطرفين
    text[left] = text[right];
    text[right] = tmp;
    reverseInPlace(text, left + 1, right - 1);
}

int main(void) {
    char text[] = "fast delivery for every order";
    int pos, start = 0, length = 0;
    while (text[length] != '\0') length++;
    reverseInPlace(text, 0, length - 1);
    printf("Whole: %s\n", text);
    reverseInPlace(text, 0, length - 1);          // نعيدها كما كانت
    for (pos = 0; pos <= length; pos++)
        if (text[pos] == ' ' || text[pos] == '\0') {
            reverseInPlace(text, start, pos - 1);  // كل كلمة على حدة
            start = pos + 1;
        }
    printf("Words: %s\n", text);
    return 0;
}
