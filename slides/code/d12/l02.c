Node *newNode(int v) {
    Node *n = malloc(sizeof(Node));
    if (n == NULL) exit(1);
    n->value = v;
    n->next = NULL;
    return n;
}
