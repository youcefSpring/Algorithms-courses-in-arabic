#include <stdio.h>

int main(void) {
    char msg[] = "HELLO";
    int i, key = 3;
    for (i = 0; msg[i] != '\0'; i++)
        msg[i] = (msg[i] - 'A' + key) % 26 + 'A';
    printf("Encrypted: %s\n", msg);
    return 0;
}
