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
            return;
        }
        node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = n;
    }

    

    bool isCircular() {
        if (head == NULL) return false;

        node* temp = head->next;  // start from next node to avoid instant return
        while (temp != NULL) {
            if (temp == head) return true; // came back to head
            temp = temp->next;
        }
        return false; // reached NULL -> not circular
    }
};

int main() {
    linkedlist l;
    l.insert(10);
    l.insert(20);
    l.insert(30);
    l.insert(40);

  

    if (l.isCircular())
        cout << "Circular Linked List";
    else
        cout << "Not Circular Linked List";

    return 0;
}

