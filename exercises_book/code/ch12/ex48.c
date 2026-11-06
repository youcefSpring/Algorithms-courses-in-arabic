#include <stdio.h>

typedef struct Cat { char name[14]; int depth; struct Cat *next, *child; } Cat;

void flatten(Cat *head) {
    Cat *walk, *tail;
    for (walk = head; walk != NULL; walk = walk->next) {
        if (walk->child == NULL) continue;
        for (tail = walk->child; ; tail = tail->next) {
            tail->depth = walk->depth + 1;             // عمق الأبناء
            if (tail->next == NULL) break;
        }
        tail->next = walk->next;                       // الأبناء قبل الإخوة
        walk->next = walk->child;
        walk->child = NULL;
    }
}

int main(void) {
    Cat nodes[11] = {{"Electronics", 0, 0, 0}, {"Phones", 0, 0, 0}, {"Android", 0, 0, 0},
                     {"iOS", 0, 0, 0}, {"Computers", 0, 0, 0}, {"Laptops", 0, 0, 0},
                     {"Gaming", 0, 0, 0}, {"Office", 0, 0, 0}, {"Home", 0, 0, 0},
                     {"Kitchen", 0, 0, 0}, {"Garden", 0, 0, 0}};
    Cat *walk;
    nodes[0].next = &nodes[8];                                   // المستوى 0
    nodes[0].child = &nodes[1]; nodes[1].next = &nodes[4];       // Electronics
    nodes[1].child = &nodes[2]; nodes[2].next = &nodes[3];       // Phones
    nodes[4].child = &nodes[5];                                  // Computers
    nodes[5].child = &nodes[6]; nodes[6].next = &nodes[7];       // Laptops
    nodes[8].child = &nodes[9]; nodes[9].next = &nodes[10];      // Home
    flatten(&nodes[0]);
    for (walk = &nodes[0]; walk != NULL; walk = walk->next)
        printf("%*s%s\n", 2 * walk->depth, "", walk->name);
    return 0;
}
