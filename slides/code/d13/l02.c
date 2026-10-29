Node *newNode(int v) {
    Node *n = malloc(sizeof(Node));
    n->value = v;
    n->left = NULL;
    n->right = NULL;
    return n;
}
