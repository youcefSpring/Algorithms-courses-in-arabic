#include <stdio.h>
#include <stdlib.h>

typedef struct Digit { int value; struct Digit *next; } Digit;

Digit *fromText(const char *text) {
    Digit *head = NULL, *node;
    for (; *text != '\0'; text++) {
        node = malloc(sizeof(Digit));
        node->value = *text - '0';
        node->next = head;                    // الآحاد تنتهي في الرأس
        head = node;
    }
    return head;
}

Digit *addNumbers(const Digit *first, const Digit *second) {
    Digit dummy, *tail = &dummy, *node;
    int carry = 0, digit;
    while (first != NULL || second != NULL || carry) {
        digit = carry + (first ? first->value : 0) + (second ? second->value : 0);
        node = malloc(sizeof(Digit));
        node->value = digit % 10;
        node->next = NULL;
        tail->next = node;
        tail = node;
        carry = digit / 10;                   // الحمل
        if (first) first = first->next;
        if (second) second = second->next;
    }
    return dummy.next;
}

void printNumber(const Digit *head) {
    if (head == NULL) return;
    printNumber(head->next);                  // الأرقام الأعلى أولًا
    printf("%d", head->value);
}

void freeDigits(Digit *head) { Digit *next; for (; head != NULL; head = next) { next = head->next; free(head); } }

int main(void) {
    Digit *first = fromText("98765432109876543210"), *second = fromText("12345678901234567890");
    Digit *sum = addNumbers(first, second);
    printf("  "); printNumber(first); printf("\n+ "); printNumber(second);
    printf("\n= "); printNumber(sum); printf("\n");
    freeDigits(first); freeDigits(second); freeDigits(sum);
    return 0;
}
