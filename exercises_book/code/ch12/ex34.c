#include <stdio.h>
#include <stdlib.h>

typedef struct Node { char ch; struct Node *next; } Node;

Node *reverse(Node *head) {
    Node *prev = NULL, *next;
    while (head != NULL) { next = head->next; head->next = prev; prev = head; head = next; }
    return prev;
}

int isPalindrome(Node *head) {
    Node *slow = head, *fast = head, *second, *left, *right;
    int same = 1;
    while (fast != NULL && fast->next != NULL) { slow = slow->next; fast = fast->next->next; }
    second = reverse(slow);                              // نقلب النصف الثاني
    for (left = head, right = second; right != NULL; left = left->next, right = right->next)
        if (left->ch != right->ch) { same = 0; break; }
    reverse(second);                                     // نعيده كما كان
    return same;
}

Node *fromText(const char *text) {
    Node dummy, *tail = &dummy;
    for (; *text != '\0'; text++) {
        tail->next = malloc(sizeof(Node));
        tail = tail->next;
        tail->ch = *text;
    }
    tail->next = NULL;
    return dummy.next;
}

int main(void) {
    const char *codes[3] = {"AB1221BA", "XY-7-YX", "SKU2026"};
    Node *head, *walk, *next;
    int idx;
    for (idx = 0; idx < 3; idx++) {
        head = fromText(codes[idx]);
        printf("%-9s %-14s list after: ", codes[idx], isPalindrome(head) ? "palindrome" : "not palindrome");
        for (walk = head; walk != NULL; walk = walk->next) putchar(walk->ch);
        printf("\n");
        for (walk = head; walk != NULL; walk = next) { next = walk->next; free(walk); }
    }
    return 0;
}
