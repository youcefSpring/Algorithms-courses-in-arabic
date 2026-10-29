Node *append(Node *head, int v) {
    Node *n = newNode(v), *p = head;
    if (head == NULL)
        return n;
    while (p->next != NULL)     /* go to the last node */
        p = p->next;
    p->next = n;
    return head;
}
