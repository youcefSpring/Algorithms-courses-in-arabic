#include <stdio.h>

int main(void) {
    float a, b;
    char op;
    printf("Operation: ");
    scanf("%f %c %f", &a, &op, &b);
    switch (op) {
        case '+': printf("= %.2f\n", a + b); break;
        case '-': printf("= %.2f\n", a - b); break;
        case '*': printf("= %.2f\n", a * b); break;
        case '/': printf("= %.2f\n", a / b); break;
        default:  printf("Unknown operator\n");
    }
    return 0;
}
