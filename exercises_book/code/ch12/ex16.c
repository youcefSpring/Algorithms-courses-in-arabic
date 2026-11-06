#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int amount; struct Node *next; } Node;

Node *middle(Node *head) {
    Node *slow = head, *fast = head;
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;              // خطوة
        fast = fast->next->next;        // خطوتان
    }
    return slow;
}

Node *fromArray(const int *values, int size) {
    Node *head = NULL, *node;
    while (size-- > 0) { node = malloc(sizeof(Node)); node->amount = values[size]; node->next = head; head = node; }
    return head;
}

void freeList(Node *head) { Node *next; while (head != NULL) { next = head->next; free(head); head = next; } }

int main(void) {
    int oddList[7] = {450, 899, 1200, 1500, 3200, 4100, 7800};
    int evenList[6] = {300, 650, 990, 2200, 5400, 9900};
    Node *first = fromArray(oddList, 7), *second = fromArray(evenList, 6);
    printf("7 orders -> middle %d\n", middle(first)->amount);
    printf("6 orders -> middle (second of the two) %d\n", middle(second)->amount);
    freeList(first);
    freeList(second);
    return 0;
}
