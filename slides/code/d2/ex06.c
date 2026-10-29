#include <stdio.h>

int main(void) {
    char key = 'd';
    int x = 5, y = 5;
    switch (key) {
        case 'w': y--; break;
        case 's': y++; break;
        case 'a': x--; break;
        case 'd': x++; break;
        default:  printf("Unknown key\n");
    }
    printf("Position: (%d, %d)\n", x, y);
    return 0;
}
