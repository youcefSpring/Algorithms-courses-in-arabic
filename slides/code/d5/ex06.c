#include <stdio.h>

int main(void) {
    char b[3][3] = {{'X', 'O', 'X'},
                    {'O', 'O', 'O'},
                    {'X', 'X', ' '}};
    int i;
    for (i = 0; i < 3; i++)
        if (b[i][0] != ' ' && b[i][0] == b[i][1]
                           && b[i][1] == b[i][2])
            printf("%c wins on row %d\n", b[i][0], i + 1);
    return 0;
}
