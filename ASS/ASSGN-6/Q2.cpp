#include<iostream>
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

class CLL {
public:
    node* head;
    node* tail;

    CLL() {
        head = NULL;
        tail = NULL;
    }

    void insert(int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            tail = n;
            tail->next = head;
            return;
        }
        tail->next = n;
        tail = n;
        tail->next = head;
    }

    void display() {
        if (head == NULL) return;
        node* temp = head;
        while (temp->next != head) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << temp->val << " ";
        cout << head->val << endl; // repeat head node
    }
};

int main() {
    CLL c;
    c.insert(20);
    c.insert(100);
    c.insert(40);
    c.insert(80);
    c.insert(60);
    c.display();
}


