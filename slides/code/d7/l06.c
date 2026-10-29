#include <stdio.h>

int counter = 0;            /* global */

void visit(void) {
    int local = 10;         /* local */
    counter++;
    printf("local=%d counter=%d\n", local, counter);
}

int main(void) {
    visit();
    visit();
    return 0;
}
