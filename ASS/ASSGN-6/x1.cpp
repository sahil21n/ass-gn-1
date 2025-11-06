Node* middle(Node* head){
    Node* slow = head;
    Node* fast = head;
        
    while (fast->next != head && fast->next->next != head) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;       
}

Node* gettail(Node* head){
    Node* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    return temp;
}

class Solution {
public:
    pair<Node*, Node*> splitList(Node *head) {

        if (head == NULL || head->next == head) {
            return {head, NULL}; // Only 0 or 1 node
        }

        // 1. Find mid (slow) and tail
        Node* mid = middle(head);
        Node* head2 = mid->next;
        Node* tail = gettail(head);

        // 2. Make first half circular
        mid->next = head;

        // 3. Make second half circular
        tail->next = head2;

        // 4. Return both heads
        return {head, head2};
    }
};
