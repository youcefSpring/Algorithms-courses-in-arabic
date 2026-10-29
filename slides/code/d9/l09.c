#include <stdio.h>

typedef struct { int d, m, y; } Date;

typedef struct { char name[20]; Date birth; } Person;

int main(void) {
    Person p = {"Karim", {12, 3, 2006}};
    printf("%s: %02d/%02d/%d\n", p.name,
           p.birth.d, p.birth.m, p.birth.y);
    return 0;
}
