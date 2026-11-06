#include <stdio.h>
#include <stdlib.h>

typedef struct Node { char name[12]; double price; struct Node *next; } Node;

Node *insertSorted(Node *head, const char *name, double price) {
    Node *node = malloc(sizeof(Node)), *walk;
    int pos;
    for (pos = 0; (node->name[pos] = name[pos]) != '\0'; pos++) {}
    node->price = price;
    if (head == NULL || price < head->price) {        // في الرأس
        node->next = head;
        return node;
    }
    walk = head;
    while (walk->next != NULL && walk->next->price < price) walk = walk->next;
    node->next = walk->next;                          // الربط بالتالي أولًا
    walk->next = node;
    return head;
}

int main(void) {
    const char *names[6] = {"Monitor", "Mouse", "Laptop", "Cable", "Keyboard", "Webcam"};
    double prices[6] = {32000, 1500, 89000, 450, 3200, 4100};
    Node *head = NULL, *walk, *next;
    int idx;
    for (idx = 0; idx < 6; idx++) head = insertSorted(head, names[idx], prices[idx]);
    for (walk = head; walk != NULL; walk = walk->next) printf("%s(%.0f) ", walk->name, walk->price);
    printf("\n");
    for (walk = head; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
