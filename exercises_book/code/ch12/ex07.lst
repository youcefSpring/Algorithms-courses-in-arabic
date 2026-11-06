#include <stdio.h>
#include <stdlib.h>

typedef struct Node { char name[12]; double price; struct Node *next; } Node;

Node *pushFront(Node *head, const char *name, double price) {
    Node *node = malloc(sizeof(Node));
    int pos;
    for (pos = 0; (node->name[pos] = name[pos]) != '\0'; pos++) {}
    node->price = price;
    node->next = head;
    return node;
}

Node *mostExpensive(Node *head) {
    Node *best = head, *walk;
    if (head == NULL) return NULL;
    for (walk = head->next; walk != NULL; walk = walk->next)
        if (walk->price > best->price) best = walk;
    return best;
}

int main(void) {
    Node *head = NULL, *best, *next;
    head = pushFront(head, "Mouse", 1500);
    head = pushFront(head, "Laptop", 89000);
    head = pushFront(head, "Monitor", 32000);
    head = pushFront(head, "Cable", 450);
    best = mostExpensive(head);
    printf("Most expensive: %s (%.0f DA)\n", best->name, best->price);
    while (head != NULL) { next = head->next; free(head); head = next; }
    return 0;
}
