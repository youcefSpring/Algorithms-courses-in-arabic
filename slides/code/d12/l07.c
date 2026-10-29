Node *popFront(Node *head) {
    Node *old = head;
    if (head == NULL)
        return NULL;
    head = head->next;
    free(old);
    return head;
}
