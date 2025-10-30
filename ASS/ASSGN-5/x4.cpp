#include<iostream>
using namespace std;

struct Node {
    int val;
    Node* next;
    Node(int val) {
        this->val = val;
        next = NULL;
    }
};

class Solution {
public:
    Node* rotate(Node* head, int k) {
        // hi, I am Sahil
        if(k == 0 || head == NULL || head->next == NULL) return head;

        Node* temp = head;
        Node* tail = head;

        int size = 1;

        while(tail->next != NULL){
            tail = tail->next;
            size++;
        }

        k = k % size;
        if(k == 0) return head;

        for(int i = 1; i <= k - 1; i++){
            temp = temp->next;
        }

        tail->next = head;        // make it circular temporarily
        head = temp->next;        // new head
        temp->next = NULL;        // break the link

        return head;
    }

    void display(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    Node* head = new Node(10);
    head->next = new Node(20);
    head->next->next = new Node(30);
    head->next->next->next = new Node(40);
    head->next->next->next->next = new Node(50);

    Solution s;
    cout << "Original list: ";
    s.display(head);

    head = s.rotate(head, 2);

    cout << "After rotation: ";
    s.display(head);

    return 0;
}
