#include <stdio.h>
#include <stdlib.h>

typedef struct Node { char name[10]; struct Node *next, *related; } Node;

Node *cloneList(Node *head) {
    Node *walk, *copy, *cloneHead;
    int pos;
    for (walk = head; walk != NULL; walk = copy->next) {          // 1) تشبيك
        copy = malloc(sizeof(Node));
        for (pos = 0; (copy->name[pos] = walk->name[pos]) != '\0'; pos++) {}
        copy->next = walk->next;
        walk->next = copy;
    }
    for (walk = head; walk != NULL; walk = walk->next->next)       // 2) روابط التوصية
        walk->next->related = walk->related != NULL ? walk->related->next : NULL;
    cloneHead = head != NULL ? head->next : NULL;
    for (walk = head; walk != NULL; walk = walk->next) {           // 3) الفصل
        copy = walk->next;
        walk->next = copy->next;
        copy->next = copy->next != NULL ? copy->next->next : NULL;
    }
    return cloneHead;
}

void show(const char *label, Node *head, Node *other) {
    Node *walk;
    printf("%s", label);
    for (walk = head; walk != NULL; walk = walk->next) {
        printf(" %s->%s", walk->name, walk->related ? walk->related->name : "-");
        if (walk->related != NULL && other != NULL && walk->related == other) printf("(!)");
    }
    printf("\n");
}

int main(void) {
    Node items[5] = {{"Phone", NULL, NULL}, {"Case", NULL, NULL}, {"Charger", NULL, NULL},
                     {"Laptop", NULL, NULL}, {"Mouse", NULL, NULL}};
    Node *clone, *walk, *next, *inside;
    int idx, independent = 1;
    for (idx = 0; idx < 4; idx++) items[idx].next = &items[idx + 1];
    items[0].related = &items[1]; items[1].related = &items[0];
    items[2].related = &items[0]; items[3].related = &items[4];
    clone = cloneList(&items[0]);
    show("original:", &items[0], NULL);
    show("clone:   ", clone, NULL);
    for (walk = clone; walk != NULL; walk = walk->next)            // هل تشير النسخة إلى الأصل؟
        for (inside = &items[0]; inside != NULL; inside = inside->next)
            if (walk->related == inside) independent = 0;
    printf("clone links stay inside clone: %s\n", independent ? "yes" : "no");
    for (walk = clone; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
