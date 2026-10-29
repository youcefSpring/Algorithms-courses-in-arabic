void freeTree(Node *t) {
    if (t == NULL)
        return;
    freeTree(t->left);
    freeTree(t->right);
    free(t);         /* the node after its children */
}
