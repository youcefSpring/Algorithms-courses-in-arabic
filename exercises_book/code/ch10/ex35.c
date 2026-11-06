#include <stdio.h>
#include <stdlib.h>

typedef struct { char *data; int capacity, top; } Stack;

Stack createStack(int capacity) {
    Stack stack;
    stack.data = malloc(capacity);
    stack.capacity = capacity;
    stack.top = 0;
    return stack;
}

void push(Stack *stack, char value) {
    char *bigger;
    int idx;
    if (stack->top == stack->capacity) {            // نضاعف السعة
        bigger = malloc(2 * stack->capacity);
        for (idx = 0; idx < stack->top; idx++) bigger[idx] = stack->data[idx];
        free(stack->data);
        stack->data = bigger;
        stack->capacity *= 2;
    }
    stack->data[stack->top++] = value;
}

char pop(Stack *stack) { return stack->top > 0 ? stack->data[--stack->top] : '\0'; }
void destroyStack(Stack *stack) { free(stack->data); stack->data = NULL; }

int main(void) {
    char text[] = "{div:[{p:(price*(1+tax))},{ul:[(a),(b),{c:[(d)]}]}]}";
    Stack stack = createStack(2);
    int pos, balanced = 1, deepest = 0;
    char open, close;
    for (pos = 0; text[pos] != '\0' && balanced; pos++) {
        close = text[pos];
        if (close == '(' || close == '[' || close == '{') {
            push(&stack, close);
            if (stack.top > deepest) deepest = stack.top;
        } else if (close == ')' || close == ']' || close == '}') {
            open = pop(&stack);
            balanced = (open == '(' && close == ')') || (open == '[' && close == ']') ||
                       (open == '{' && close == '}');
        }
    }
    if (stack.top != 0) balanced = 0;
    printf("%s, max depth %d, final capacity %d\n", balanced ? "balanced" : "unbalanced",
           deepest, stack.capacity);
    destroyStack(&stack);
    return 0;
}
