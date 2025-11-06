class Solution {
public:
    
    ListNode* simpleReverse(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* current = head;
        ListNode* next_node = NULL;

        while (current != NULL) {
            next_node = current->next;
            current->next = prev;
            prev = current;
            current = next_node;
        }
        return prev; // Returns the new head (original tail)
    }

    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || k <= 1) {
            return head;
        }

        // 1. Find the k-th node to define the segment
        ListNode* segment_tail = head; // This is the (k-1)th node's next
        int count = 1;
        
        while (count < k && segment_tail != NULL) {
            segment_tail = segment_tail->next;
            count++;
        }

        // Check if there are k nodes
        if (segment_tail == NULL) {
            return head; // Not enough nodes
        }
        
        // At this point, segment_tail is the k-th node.

        // 2. BREAK the list and save the head of the rest
        ListNode* next_group_start = segment_tail->next; // Save the k+1 node
        segment_tail->next = NULL;                       // TEMPORARILY BREAK THE LINK

        // 3. REVERSE the separated segment
        // 'new_head' is the k-th node; 'head' (the original head) is now the new tail.
        ListNode* new_head = simpleReverse(head);
        ListNode* new_tail = head; // The original head is now the tail of the reversed segment

        // 4. Recursively process and RECONNECT
        // The new tail connects to the result of the recursive call.
        ListNode* reversed_rest = reverseKGroup(next_group_start, k);
        new_tail->next = reversed_rest;

        // 5. Return the new head of the entire segment
        return new_head;
    }
};
