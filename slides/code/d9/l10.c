#include <stdio.h>

typedef struct { char name[20]; float avg; } Student;

int main(void) {
    Student c[4] = {{"Amina", 14.5}, {"Yacine", 11.25},
                    {"Sara", 16}, {"Nadir", 15.75}};
    int i, b = 0;
    for (i = 1; i < 4; i++)
        if (c[i].avg > c[b].avg)
            b = i;
    printf("Best: %s (%.2f)\n", c[b].name, c[b].avg);
    return 0;
}
