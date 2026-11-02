#include <stdio.h>

int main(void) {
    char source[] = "Gaming Laptop";
    char copy[50];
    int pos = 0;
    while (source[pos] != '\0') {
        copy[pos] = source[pos];      // حرفًا بحرف
        pos++;
    }
    copy[pos] = '\0';                 // ضروري: علامة النهاية
    copy[0] = 'X';                    // نعدل النسخة فقط
    printf("Source: %s\nCopy:   %s\n", source, copy);
    return 0;
}
