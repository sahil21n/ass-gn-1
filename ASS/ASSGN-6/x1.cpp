#include <iostream>
using namespace std;

class node {
public:
    int val;
    node* next;
    node(int val) {
        this->val = val;
        next = NULL;
    }
};

class linkedlist {
public:
    node* head;
    linkedlist() {
        head = NULL;
    }

    void insert(int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            head->next = head; // circular
            return;
        }
        node* temp = head;
        while (temp->next != head) {
            temp = temp->next;
        }
        temp->next = n;
        n->next = head;
    }

    void split() {
        if (head == NULL || head->next == head) {
            cout << "Not enough nodes to split.";
            return;
        }

        node* slow = head;
        node* fast = head;

        // find left middle
        while (fast->next != head && fast->next->next != head) {
            slow = slow->next;
            fast = fast->next->next;
        }

        node* p = slow->next;   // start of 2nd half
        slow->next = head;      // close first circle

        node* temp = p;
        while (temp->next != head) {  // find end of 2nd half
            temp = temp->next;
        }
        temp->next = p;  // close second circle

        cout << "First half: ";
        display(head);
        cout << "\nSecond half: ";
        display(p);
    }

    void display(node* start) {
        if (start == NULL) return;

        node* temp = start;
        cout << temp->val << " ";
        temp = temp->next;

        while (temp != start) {
            cout << temp->val << " ";
            temp = temp->next;
        }
    }
};

int main() {
    linkedlist l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);
    l.insert(50);
    l.insert(60);
    l.insert(70);

    l.split();

    return 0;
}
