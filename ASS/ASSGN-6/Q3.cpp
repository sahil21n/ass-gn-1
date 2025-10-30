#include<iostream>
using namespace std;

class DLL {
public:
    class node {
    public:
        int val;
        node* next;
        node* prev;
        node(int val) {
            this->val = val;
            next = NULL;
            prev = NULL;
        }
    };

    node* head;

    DLL() {
        head = NULL;
    }

    void insert(int val) {
        node* n = new node(val);
        if (head == NULL) {
            head = n;
            return;
        }
        node* temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    int size() {
        int count = 0;
        node* temp = head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
};

class CLL {
public:
    class node {
    public:
        int val;
        node* next;
        node(int val) {
            this->val = val;
            next = NULL;
        }
    };

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

    int size() {
        if (head == NULL) return 0;
        int count = 0;
        node* temp = head;
        while (temp->next != head) {
            count++;
            temp = temp->next;
        }
        count++;
        return count;
    }
};

int main() {
    DLL d;
    d.insert(10);
    d.insert(20);
    d.insert(30);
    cout << "Size of Doubly Linked List: " << d.size() << endl;

    CLL c;
    c.insert(5);
    c.insert(15);
    c.insert(25);
    cout << "Size of Circular Linked List: " << c.size() << endl;
}
