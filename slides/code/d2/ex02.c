#include <stdio.h>

int main(void) {
    int home = 2, away = 2, points;
    if (home > away)
        points = 3;
    else if (home == away)
        points = 1;
    else
        points = 0;
    printf("Points = %d\n", points);
    return 0;
}
