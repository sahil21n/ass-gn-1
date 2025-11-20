void correctDLL(Node* head) {

    if (head == NULL) return;

    Node* temp = head;

    while (temp != NULL) {

        // Check if next pointer’s prev is wrong
        if (temp->next != NULL && temp->next->prev != temp) {
            temp->next->prev = temp;   // fix it
            break;                     // only one wrong pointer as per question
        }

        // Check if prev pointer’s next is wrong
        if (temp->prev != NULL && temp->prev->next != temp) {
            temp->prev->next = temp;   // fix it
            break;
        }

        temp = temp->next;
    }
}
