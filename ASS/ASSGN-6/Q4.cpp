#include<iostream>
using namespace std;

class node{
public:
    int val;
    node* next;
    node* prev;

    node(int val){
        this->val = val;
        next = NULL;
        prev = NULL;
    }
};

class doublyLL{
public:
    node* head;

    doublyLL(){
        head = NULL;
    }

    void insertAtEnd(int val){
        node* n = new node(val);
        if(head == NULL){
            head = n;
            return;
        }
        node* temp = head;
        while(temp->next) temp = temp->next;
        temp->next = n;
        n->prev = temp;
    }

    bool checkPalindrome(){
        if(!head || !head->next) return true;

        node* i = head;
        node* j = head;

        // move j to the end
        while(j->next) j = j->next;

        // compare from both sides
        while(i != j && j->next != i){
            if(i->val != j->val) return false;
            i = i->next;
            j = j->prev;
        }

        return true;
    }

    void display(){
        node* temp = head;
        while(temp){
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    doublyLL d;
    d.insertAtEnd(1);
    d.insertAtEnd(2);
    d.insertAtEnd(2);
    d.insertAtEnd(1);

    d.display();

    if(d.checkPalindrome()) cout << "Palindrome";
    else cout << "Not Palindrome";

    return 0;
}
