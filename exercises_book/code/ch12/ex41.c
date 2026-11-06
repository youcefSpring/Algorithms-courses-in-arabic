#include <stdio.h>
#include <stdlib.h>

typedef struct Node { int number; double amount; struct Node *next; } Node;

Node *merge(Node *first, Node *second) {
    Node dummy, *tail = &dummy;
    while (first != NULL && second != NULL) {
        if (first->amount <= second->amount) { tail->next = first; first = first->next; }
        else { tail->next = second; second = second->next; }
        tail = tail->next;
    }
    tail->next = first != NULL ? first : second;
    return dummy.next;
}

Node *mergeSort(Node *head) {
    Node *slow, *fast, *second;
    if (head == NULL || head->next == NULL) return head;
    slow = head;
    fast = head->next;
    while (fast != NULL && fast->next != NULL) { slow = slow->next; fast = fast->next->next; }
    second = slow->next;                        // النصف الثاني
    slow->next = NULL;                          // نقطع القائمة
    return merge(mergeSort(head), mergeSort(second));
}

int main(void) {
    double amounts[12] = {4500, 1200, 899, 27000, 650, 3200, 12500, 99, 7800, 2300, 560, 4100};
    Node *head = NULL, *node, *walk, *next;
    int idx;
    for (idx = 11; idx >= 0; idx--) {
        node = malloc(sizeof(Node)); node->number = 7781 + idx; node->amount = amounts[idx];
        node->next = head; head = node;
    }
    head = mergeSort(head);
    for (walk = head; walk != NULL; walk = walk->next) printf("#%d:%.0f ", walk->number, walk->amount);
    printf("\n");
    for (walk = head; walk != NULL; walk = next) { next = walk->next; free(walk); }
    return 0;
}
