Node *insert(Node *t, int v) {
    if (t == NULL)
        return newNode(v);
    if (v < t->value)
        t->left = insert(t->left, v);
    else
        t->right = insert(t->right, v);
    return t;
}
