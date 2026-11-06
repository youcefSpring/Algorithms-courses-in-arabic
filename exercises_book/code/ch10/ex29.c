#include <stdio.h>

const char *findText(const char *haystack, const char *needle) {
    const char *start, *left, *right;
    for (start = haystack; *start != '\0'; start++) {
        left = start;
        right = needle;
        while (*right != '\0' && *left == *right) { left++; right++; }
        if (*right == '\0') return start;         // كل needle طابقت
    }
    return NULL;
}

int main(void) {
    const char *text = "usb cable, usb charger and usb-c hub with usb 3.0 support";
    const char *word = "usb";
    const char *pos = findText(text, word);
    int count = 0;
    printf("Positions of \"%s\":", word);
    while (pos != NULL) {
        printf(" %d", (int)(pos - text));
        count++;
        pos = findText(pos + 1, word);            // نواصل بعد آخر ظهور
    }
    printf("\n%d occurrences\n", count);
    printf("\"hdmi\" found: %s\n", findText(text, "hdmi") ? "yes" : "no");
    return 0;
}
