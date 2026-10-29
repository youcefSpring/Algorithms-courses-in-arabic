#include <stdio.h>

int main(void) {
    int xp = 10000, need = 100, level = 1;
    while (xp >= need) {
        xp -= need;
        level++;
        need *= 2;
    }
    printf("Level = %d\n", level);
    printf("XP left = %d\n", xp);
    return 0;
}
