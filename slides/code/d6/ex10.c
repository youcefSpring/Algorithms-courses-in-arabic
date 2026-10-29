#include <stdio.h>
#include <string.h>

int main(void) {
    char phone[] = "0555123489";
    int i, n = strlen(phone);
    for (i = 4; i < n - 2; i++)
        phone[i] = '*';
    printf("Phone: %s\n", phone);
    return 0;
}
