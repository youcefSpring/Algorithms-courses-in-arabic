void freeList(Node *head) {
    Node *t;
    while (head != NULL) {
        t = head;
        head = head->next;
        free(t);
    }
}
