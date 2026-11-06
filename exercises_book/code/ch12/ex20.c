#include <stdio.h>
#include <stdlib.h>

typedef struct Page { char name[16]; struct Page *prev, *next; } Page;

int main(void) {
    char command[24];
    Page *current = NULL, *node, *walk, *next, *first = NULL;
    int pos;
    while (scanf("%23s", command) == 1) {
        if (command[0] == 'v') {
            if (current != NULL)                                // نحذف تاريخ التقدم
                for (walk = current->next; walk != NULL; walk = next) { next = walk->next; free(walk); }
            node = malloc(sizeof(Page));
            for (pos = 0; (node->name[pos] = command[pos + 2]) != '\0'; pos++) {}
            node->prev = current;
            node->next = NULL;
            if (current != NULL) current->next = node; else first = node;
            current = node;
        } else if (command[0] == 'b' && current->prev != NULL) {
            current = current->prev;
        } else if (command[0] == 'f' && current->next != NULL) {
            current = current->next;
        }
        printf("%-10s -> now on %s\n", command, current->name);
    }
    for (walk = first; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
