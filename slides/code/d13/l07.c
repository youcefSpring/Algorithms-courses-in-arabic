int search(Node *t, int x) {
    if (t == NULL) return 0;          /* not found */
    if (x == t->value) return 1;      /* found */
    if (x < t->value)
        return search(t->left, x);
    return search(t->right, x);
}
