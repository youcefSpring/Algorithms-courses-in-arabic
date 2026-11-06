#include <stdio.h>

int maxDepth = 0;

int parse(char text[], int pos, int depth, char closing) {
    char ch;
    if (depth > maxDepth) maxDepth = depth;
    while (text[pos] != '\0') {
        ch = text[pos];
        if (ch == '{' || ch == '[') {
            pos = parse(text, pos + 1, depth + 1, ch == '{' ? '}' : ']');   // كتلة داخلية
            if (pos < 0) return -1;
        } else if (ch == '}' || ch == ']') {
            return ch == closing ? pos + 1 : -1;     // يجب أن يطابق قوس الفتح
        } else {
            pos++;
        }
    }
    return closing == '\0' ? pos : -1;               // نهاية النص
}

int main(void) {
    char good[] = "{shop:{name:x,cats:[{id:1,tags:[a,b]},{id:2}]},pay:[cash]}";
    char bad[] = "{shop:{cats:[{id:1]}}";
    int end;
    end = parse(good, 0, 0, '\0');
    printf("Config 1: %s, max depth %d\n", end >= 0 ? "balanced" : "unbalanced", maxDepth);
    maxDepth = 0;
    end = parse(bad, 0, 0, '\0');
    printf("Config 2: %s\n", end >= 0 ? "balanced" : "unbalanced");
    return 0;
}
