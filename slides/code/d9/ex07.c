#include <stdio.h>

typedef struct { char name[15]; float rating; } App;

int main(void) {
    App a[4] = {{"Maps", 4.3}, {"Notes", 4.8},
                {"Camera", 4.1}, {"Health", 4.6}};
    int i, b = 0;
    float sum = 0;
    for (i = 0; i < 4; i++) {
        sum += a[i].rating;
        if (a[i].rating > a[b].rating)
            b = i;
    }
    printf("Best: %s (%.1f)\n", a[b].name, a[b].rating);
    printf("Average: %.2f\n", sum / 4);
    return 0;
}
