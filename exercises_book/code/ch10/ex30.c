#include <stdio.h>

char *trim(char *text) {
    char *start = text, *end;
    while (*start == ' ') start++;               // فراغات البداية
    if (*start == '\0') return start;             // نص فارغ
    end = start;
    while (*(end + 1) != '\0') end++;             // آخر حرف
    while (end > start && *end == ' ') end--;     // فراغات النهاية
    *(end + 1) = '\0';
    return start;
}

int main(void) {
    char inputs[3][40] = {"   amina@mail.dz  ", "Oran   ", "      "};
    int idx;
    for (idx = 0; idx < 3; idx++)
        printf("[%s]\n", trim(inputs[idx]));
    return 0;
}
