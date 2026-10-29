#include <stdio.h>

typedef struct { char name[20]; int age; } Person;

void birthday(Person *p) {
    p->age++;              /* same as (*p).age++ */
}

int main(void) {
    Person a = {"Amina", 19};
    birthday(&a);
    printf("%s: %d\n", a.name, a.age);
    return 0;
}
