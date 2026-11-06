#include <stdio.h>

int main(void) {
    char expr[100], ch, op = '+';
    long total = 0, term = 0, number = 0;
    int pos, sign = 1;
    scanf("%99s", expr);
    for (pos = 0; ; pos++) {
        ch = expr[pos];
        if (ch >= '0' && ch <= '9') {
            number = number * 10 + (ch - '0');        // تحويل يدوي
            continue;
        }
        if (op == '*')      term = term * number;     // أولوية الضرب
        else if (op == '/') term = term / number;
        else                term = number;            // بداية حد جديد
        if (ch == '+' || ch == '-' || ch == '\0') {
            total += sign * term;                     // الحد اكتمل
            sign = (ch == '-') ? -1 : 1;
            op = '+';
        } else {
            op = ch;                                  // * أو /
        }
        number = 0;
        if (ch == '\0') break;
    }
    printf("%s = %ld DA\n", expr, total);
    return 0;
}
