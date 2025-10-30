#include <iostream>
using namespace std;

class SNode {
public:
    int val;
    SNode* next;

    SNode(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class CircularSLL {
public:
    SNode* head;
    int size;

    CircularSLL() {
        head = NULL;
        size = 0;
    }

    void insertAtTail(int val) {
        SNode* t = new SNode(val);
        
        if (size == 0) {
            head = t;
            t->next = head;
        } else {
            SNode* temp = head;
            while (temp->next != head) {
                temp = temp->next;
            }
            temp->next = t;
            t->next = head;
        }
        size++;
    }

    void insertAtHead(int val) {
        SNode* temp = new SNode(val);
        
        if (size == 0) {
            head = temp;
            temp->next = head;
        } else {
            SNode* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            temp->next = head;
            tail->next = temp;
            head = temp;
        }
        size++;
    }

    void deleteAtHead() {
        if (size == 0) {
            cout << "CSLL is empty!" << endl;
            return;
        }
        
        SNode* temp = head; 
        if (size == 1) {
            head = NULL;
        } else {
            SNode* tail = head;
            while (tail->next != head) {
                tail = tail->next;
            }
            head = head->next;
            tail->next = head;
        }
        delete temp;
        size--;
    }

    void display() {
        if (head == NULL) {
            cout << "CSLL is empty!" << endl;
            return;
        }
        
        SNode* temp = head;
        do {
            cout << temp->val << " -> ";
            temp = temp->next;
        } while (temp != head);
        cout << "(head)" << endl;
    }
};