#include <iostream>
#include <cmath>
using namespace std;

// Definition for singly-linked list
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:

    int size(ListNode* head){
        ListNode* temp = head;
        int ans = 0;
        while(temp != NULL){
            temp = temp->next;
            ans++;
        }
        return ans;
    }

    ListNode* getIntersectionNode(ListNode *headA, ListNode *headB) {
        int s1 = size(headA);
        int s2 = size(headB);

        int n = abs(s2 - s1);

        ListNode* t1 = headA;
        ListNode* t2 = headB;

        if(s1 > s2){
            for(int i = 1; i <= n; i++){
                t1 = t1->next;
            }
        }

        if(s1 < s2){
            for(int i = 1; i <= n; i++){
                t2 = t2->next;
            }
        }

        while(t1 != t2){
            t1 = t1->next;
            t2 = t2->next;

            if(t1 == NULL || t2 == NULL) return NULL;
        }
        return t1;
    }
};

int main(){
    // Example usage:
    // Creating 2 linked lists that intersect
    ListNode* common = new ListNode(8);
    common->next = new ListNode(10);

    ListNode* headA = new ListNode(3);
    headA->next = new ListNode(6);
    headA->next->next = new ListNode(9);
    headA->next->next->next = common;  // intersection starts here

    ListNode* headB = new ListNode(4);
    headB->next = new ListNode(7);
    headB->next->next = common;

    Solution s;
    ListNode* res = s.getIntersectionNode(headA, headB);

    if(res) cout << "Intersection at node with value: " << res->val << endl;
    else cout << "No intersection\n";

    return 0;
}
