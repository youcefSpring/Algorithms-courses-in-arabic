#include <stdio.h>

typedef struct { char title[15]; int total, done; } Course;

int main(void) {
    Course c[3] = {{"Algorithms", 24, 18},
                   {"Python", 30, 30},
                   {"Databases", 20, 5}};
    int i;
    for (i = 0; i < 3; i++)
        printf("%-11s %3.0f %%\n", c[i].title,
               c[i].done * 100.0 / c[i].total);
    return 0;
}
