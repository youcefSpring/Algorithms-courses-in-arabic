#include <stdio.h>

void move(int *x, int *y, char key) {
    switch (key) {
        case 'w': (*y)--; break;
        case 's': (*y)++; break;
        case 'a': (*x)--; break;
        case 'd': (*x)++; break;
    }
}
int main(void) {
    int x = 0, y = 0, i;
    char keys[] = "ddwwa";
    for (i = 0; keys[i] != '\0'; i++)
        move(&x, &y, keys[i]);
    printf("Position: (%d, %d)\n", x, y);
    return 0;
}
