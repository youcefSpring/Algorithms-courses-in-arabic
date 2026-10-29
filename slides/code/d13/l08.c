int count(Node *t) {
    if (t == NULL) return 0;
    return 1 + count(t->left) + count(t->right);
}

int height(Node *t) {
    int a, b;
    if (t == NULL) return 0;
    a = height(t->left);
    b = height(t->right);
    if (a > b) return 1 + a;
    return 1 + b;
}
