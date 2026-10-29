#include <stdio.h>

int matches(int teams) {
    if (teams == 1)
        return 0;
    return teams / 2 + matches(teams / 2);
}

int main(void) {
    printf("16 teams: %d matches\n", matches(16));
    printf("32 teams: %d matches\n", matches(32));
    return 0;
}
