#include <stdio.h>

typedef struct { char name[20]; int goals; } Player;

int main(void) {
    Player t[4] = {{"Mahrez", 12}, {"Slimani", 15},
                   {"Bounedjah", 18}, {"Amoura", 9}};
    int i, b = 0;
    for (i = 1; i < 4; i++)
        if (t[i].goals > t[b].goals)
            b = i;
    printf("Top scorer: %s\n", t[b].name);
    printf("Goals: %d\n", t[b].goals);
    return 0;
}
