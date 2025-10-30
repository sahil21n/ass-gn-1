#include<iostream>
using namespace std;

struct ListNode{
    int val;
    ListNode* next;
    ListNode(int val){
        this->val = val;
        next = NULL;
    }
};

class Solution{
public:

    void removeLoop(ListNode* head){
        if(head == NULL || head->next == NULL) return;

        ListNode* slow = head;
        ListNode* fast = head;
        bool loop = false;

        // Step 1: Detect loop
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;

            if(slow == fast){
                loop = true;
                break;
            }
        }

        // Step 2: If loop exists
        if(loop){
            slow = head;

            // Step 3: Find the start of the loop
            while(slow != fast){
                slow = slow->next;
                fast = fast->next;
            }

            // Step 4: Move fast till its next is the start of loop
            while(fast->next != slow){
                fast = fast->next;
            }

            // Step 5: Break the loop
            fast->next = NULL;
        }
    }

    void print(ListNode* head){
        ListNode* temp = head;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    // Example with loop
    ListNode* head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);

    // creating a loop: 5 -> 3
    head->next->next->next->next->next = head->next->next;

    Solution s;
    s.removeLoop(head);

    cout << "After removing loop:\n";
    s.print(head);

    return 0;
}
