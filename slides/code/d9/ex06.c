#include <stdio.h>

typedef struct { char name[20]; int hp, attack; } Hero;

Hero hit(Hero target, Hero from) {
    target.hp -= from.attack;
    return target;
}
int main(void) {
    Hero a = {"Knight", 100, 25};
    Hero b = {"Dragon", 60, 40};
    b = hit(b, a);
    a = hit(a, b);
    b = hit(b, a);
    printf("%s: %d HP\n", a.name, a.hp);
    printf("%s: %d HP\n", b.name, b.hp);
    return 0;
}
