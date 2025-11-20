class Solution {
public:

    // Reverse a DLL segment and return {newHead, newTail}
    pair<Node*, Node*> reverseDLL(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next_node = NULL;

        while (curr != NULL) {
            next_node = curr->next;

            curr->next = prev;
            curr->prev = next_node; // because we are reversing

            prev = curr;
            curr = next_node;
        }

        // prev becomes new head, head becomes new tail
        return {prev, head};
    }


    pair<Node*, Node*> solve(Node* head, int k) {
        if (head == NULL || k <= 1) return {head, head};

        // Step 1: Find the kth node
        Node* segment_tail = head;
        int count = 1;
        while (count < k && segment_tail != NULL) {
            segment_tail = segment_tail->next;
            count++;
        }

        // If less than k nodes, still reverse as per question
        if (segment_tail == NULL) {
            return reverseDLL(head);
        }

        // Step 2: Break the list
        Node* next_group_start = segment_tail->next;
        if (next_group_start) next_group_start->prev = NULL;
        segment_tail->next = NULL;

        // Step 3: Reverse current segment
        auto reversed = reverseDLL(head);
        Node* newHead = reversed.first;
        Node* newTail = reversed.second;

        // Step 4: Recursively process remaining nodes
        if (next_group_start != NULL) {
            auto rest = solve(next_group_start, k);
            Node* restHead = rest.first;

            // Step 5: Reconnect
            newTail->next = restHead;
            restHead->prev = newTail;

            return {newHead, rest.second};
        }

        return {newHead, newTail};
    }


    Node* reverseKGroup(Node* head, int k) {
        return solve(head, k).first;
    }

};
