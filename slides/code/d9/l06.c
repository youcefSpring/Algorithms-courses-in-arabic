#include <stdio.h>

typedef struct { char name[20]; float avg; } Student;

int main(void) {
    Student c[3] = {{"Amina", 14.5},
                    {"Yacine", 11.25},
                    {"Sara", 16}};
    int i;
    for (i = 0; i < 3; i++)
        printf("%-7s %5.2f\n", c[i].name, c[i].avg);
    return 0;
}
