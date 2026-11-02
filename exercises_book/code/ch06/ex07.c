#include <stdio.h>

int main(void) {
    char first[30], last[30], full[62];
    int pos = 0, src;
    scanf("%29s %29s", first, last);
    for (src = 0; last[src] != '\0'; src++)
        full[pos++] = last[src];      // اللقب أولًا
    full[pos++] = ' ';
    for (src = 0; first[src] != '\0'; src++)
        full[pos++] = first[src];     // ثم الاسم
    full[pos] = '\0';
    printf("Customer: %s (%d chars)\n", full, pos);
    return 0;
}
