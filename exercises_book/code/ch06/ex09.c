#include <stdio.h>

int main(void) {
    char review[] = "Worst delivery ever!!! Never again!!";
    char target;
    int count = 0, length = 0;
    scanf(" %c", &target);
    while (review[length] != '\0') {
        if (review[length] == target)
            count++;
        length++;                     // نحسب الطول في نفس المرور
    }
    printf("'%c' appears %d times (%.1f %% of text)\n", target, count, count * 100.0 / length);
    return 0;
}
