void inorder(Node *t) {
    if (t == NULL)
        return;
    inorder(t->left);
    printf("%d ", t->value);
    inorder(t->right);
}
