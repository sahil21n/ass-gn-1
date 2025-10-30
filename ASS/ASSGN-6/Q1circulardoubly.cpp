#include <iostream>
using namespace std;

class DNode {
public:
    int val;
    DNode* next;
    DNode* prev;

    DNode(int val) {
        this->val = val;
        this->next = NULL;
        this->prev = NULL;
    }
};

class CircularDLL {
public:
    DNode* head;
    DNode* tail; 
    int size;

    CircularDLL() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertAtTail(int val) {
        DNode* t = new DNode(val); 

        if (size == 0) {
            head = t;
            tail = t;
            t->next = head;
            t->prev = head;
        } else {
            tail->next = t;
            t->prev = tail;
            t->next = head;
            head->prev = t;
            tail = t;
        }
        size++;
    }

    void insertAtHead(int val) {
        DNode* t = new DNode(val);

        if (size == 0) {
            head = t;
            tail = t;
            t->next = head;
            t->prev = head;
        } else {
            t->next = head;
            head->prev = t;
            t->prev = tail;
            tail->next = t;
            head = t; 
        }
        size++;
    }

    void deleteAtTail() {
        if (size == 0) {
            cout << "CDLL is empty!" << endl;
            return;
        }

        DNode* temp = tail; 
        if (size == 1) {
            head = NULL;
            tail = NULL;
        } else {
            DNode* newTail = tail->prev;
            newTail->next = head;
            head->prev = newTail;
            tail = newTail;
        }
        delete temp;
        size--;
    }

    void display() {
        if (head == NULL) {
            cout << "CDLL is empty!" << endl;
            return;
        }

        DNode* temp = head;
        do {
            cout << temp->val << " <-> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};