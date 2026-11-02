#include <stdio.h>

int main(void) {
    char text[] = "{\"shop\": {\"name\": \"Dz(Store\", \"tags\": [\"tech\", \"home\"]}, \"open\": [8, 20]}";
    char stack[50], ch, expected;
    int pos, top = 0, ok = 1, inQuote = 0;
    for (pos = 0; text[pos] != '\0' && ok; pos++) {
        ch = text[pos];
        if (ch == '"') { inQuote = !inQuote; continue; }
        if (inQuote) continue;                // الأقواس داخل النص لا تُحسب
        if (ch == '(' || ch == '[' || ch == '{') {
            stack[top++] = ch;                // دفع
        } else if (ch == ')' || ch == ']' || ch == '}') {
            expected = (ch == ')') ? '(' : (ch == ']') ? '[' : '{';
            if (top == 0 || stack[top - 1] != expected)
                ok = 0;
            else
                top--;                        // سحب
        }
    }
    if (ok && top == 0)
        printf("Brackets are balanced\n");
    else
        printf("Unbalanced at position %d\n", pos - 1);
    return 0;
}
