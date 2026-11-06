#include <stdio.h>

void printBinary(int number) {
    if (number < 2) {
        printf("%d", number);
        return;
    }
    printBinary(number / 2);           // الأرقام الأعلى أولًا
    printf("%d", number % 2);
}

int main(void) {
    int ids[5] = {5, 13, 64, 255, 2026}, idx;
    for (idx = 0; idx < 5; idx++) {
        printf("%4d = ", ids[idx]);
        printBinary(ids[idx]);
        printf("\n");
    }
    return 0;
}
