Node *removeValue(Node *head, int x) {
    Node *p = head, *prev = NULL;
    while (p != NULL && p->value != x) {
        prev = p;
        p = p->next;
    }
    if (p == NULL) return head;          /* not found */
    if (prev == NULL) head = p->next;    /* first node */
    else prev->next = p->next;           /* skip p */
    free(p);
    return head;
}
