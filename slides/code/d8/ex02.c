#include <stdio.h>

long reach(int level) {
    if (level == 0)
        return 1;
    return 3 * reach(level - 1);
}

int main(void) {
    int l;
    for (l = 0; l <= 6; l++)
        printf("Level %d: %ld people\n", l, reach(l));
    return 0;
}
