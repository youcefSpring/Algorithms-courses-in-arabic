#include <stdio.h>
#include <stdlib.h>

typedef struct Node { double price; struct Node *next; } Node;

Node *pushFront(Node *head, double price) {
    Node *node = malloc(sizeof(Node));
    node->price = price;
    node->next = head;
    return node;
}

int length(const Node *head) {
    int count = 0;
    for (; head != NULL; head = head->next) count++;
    return count;
}

double sumPrices(const Node *head) {
    double total = 0;
    for (; head != NULL; head = head->next) total += head->price;
    return total;
}

int main(void) {
    double prices[6] = {1500, 3200, 899, 450, 12500, 2200};
    Node *head = NULL, *next;
    int idx, count;
    for (idx = 0; idx < 6; idx++) head = pushFront(head, prices[idx]);
    count = length(head);
    if (count > 0)
        printf("%d items, total %.2f, average %.2f DA\n", count, sumPrices(head), sumPrices(head) / count);
    while (head != NULL) { next = head->next; free(head); head = next; }
    return 0;
}
