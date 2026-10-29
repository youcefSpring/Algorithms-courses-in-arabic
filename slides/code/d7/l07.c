#include <stdio.h>

void change(int x) {
    x = 100;
    printf("inside: x = %d\n", x);
}

int main(void) {
    int a = 5;
    change(a);
    printf("a = %d\n", a);
    return 0;
}
