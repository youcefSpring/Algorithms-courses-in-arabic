#include <stdio.h>

int main(void) {
    double left, right, result = 0;
    char op;
    int ok = 1;                       // 1 إذا كانت العملية صالحة
    scanf("%lf %c %lf", &left, &op, &right);
    switch (op) {
        case '+': result = left + right; break;
        case '-': result = left - right; break;
        case '*': result = left * right; break;
        case '/':
            if (right == 0) ok = 0;       // لا نقسم على صفر
            else result = left / right;
            break;
        case '%': result = left * right / 100; break;   // left بالمئة من right
        default: ok = 0;
    }
    if (ok)
        printf("%.2f %c %.2f = %.2f\n", left, op, right, result);
    else
        printf("Error: invalid operation\n");
    return 0;
}
