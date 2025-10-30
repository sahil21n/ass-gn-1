// Write a program to count the number of occurrences of a given key in a singly linked
// list and then delete all the occurrences.

#include<iostream>
using namespace std;

class node {
public:
    int val;
    node* next;

    node(int val) {
        this->val = val;
        this->next = NULL;
    }
};

class LinkedList {
public:
    node* head;
    node* tail;
    int size;

    LinkedList() {
        head = tail = NULL;
        size = 0;
    }

    // --- Destructor to prevent memory leaks ---
    ~LinkedList() {
        node* temp = head;
        while (temp != NULL) {
            node* nextNode = temp->next;
            delete temp;
            temp = nextNode;
        }
        head = tail = NULL;
        size = 0;
    }

    void insertathead(int val) {
        node* temp = new node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            temp->next = head;
            head = temp;
        }
        size++;
    }

    void insertattail(int val) {
        node* temp = new node(val);
        if (size == 0) {
            head = tail = temp;
        } else {
            tail->next = temp;
            tail = temp;
        }
        size++;
    }

    // --- Corrected insertatidx ---
    // Uses 1-based indexing. idx=1 is head, idx=size+1 is tail.
    void insertatidx(int val, int idx) {
        if (idx < 1 || idx > size + 1) { // Check for valid range
            cout << "INVALID IDX" << endl;
            return;
        }
        
        if (idx == 1) {
            insertathead(val);
            return;
        }
        if (idx == size + 1) {
            insertattail(val);
            return;
        }

        // We only create the node if it's for the middle
        node* newNode = new node(val);
        node* temp = head;
        // Loop to find the node *before* the insertion point
        for (int i = 1; i <= idx - 2; i++) {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        size++;
    }

    void display() {
        node* temp = head;
        while (temp != NULL) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl; 
    }

    // --- Corrected deleteathead ---
    void deleteathead() {
        if (size == 0) {
            cout << "List is empty, cant delete" << endl;
            return;
        }
        
        node* temp = head; // Store old head to delete it
        if (size == 1) {
            head = tail = NULL;
        } else {
            head = head->next;
        }
        
        delete temp; // Free the memory
        size--;
    }

    // --- Corrected deleteattail ---
    void deleteattail() {
        if (size == 0) {
            cout << "List is empty, cant delete" << endl;
            return;
        }
        
        if (size == 1) {
            deleteathead(); // This already handles deleting and setting head/tail
            return;
        }

        // size > 1
        node* temp = head;
        // Loop to find the *second-to-last* node
        while (temp->next->next != NULL) {
            temp = temp->next;
        }
        
        delete temp->next; // Delete the last node
        temp->next = NULL;
        tail = temp; // Update the tail pointer
        size--;
    }

    // --- Corrected deleteatidx ---
    void deleteatidx(int idx) {
        if (idx < 1 || idx > size) { // Can only delete existing nodes
            cout << "Invalid index for deletion" << endl;
            return;
        }

        if (idx == 1) {
            deleteathead();
            return;
        }
        if (idx == size) {
            deleteattail();
            return;
        }

        // Deleting from the middle
        node* temp = head;
        // Loop to find the node *before* the deletion point
        for (int i = 1; i <= idx - 2; i++) {
            temp = temp->next;
        }
        
        node* nodeToDelete = temp->next;
        temp->next = nodeToDelete->next; // (or temp->next->next)
        
        delete nodeToDelete; // Free the memory
        size--;
    }

    int deleteoccu(int target){
        int count=0;
        node* prev=new node(100);
        node* a=prev;
        prev->next=head;
        node* curr=head;

        if(head==NULL) return NULL;

        while(curr!=NULL){
            if(curr->val!=target){
                curr=curr->next;
                prev=prev->next;
                
            }
            else if(curr->val==target){
                prev->next=curr->next;
                count++;
                curr=curr->next;
                size--;
            }
        }
        head=a->next;
        return count;
       

    }

    void findMiddle() {
        if (head == NULL) {
            cout << "List is empty." << endl;
            return;
        }

        node* slow = head;
        node* fast = head;

        
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        cout << "The middle element is: " << slow->val << endl;
    }

    void reverse() {
        if (size <= 1) {
            return; // No need to reverse empty or single-node list
        }

        node* prev = NULL;
        node* curr = head;
        node* nextNode = NULL;

        
       

        while (curr != NULL) {
            
            nextNode = curr->next;        
            curr->next = prev;                       
            prev = curr;
            curr = nextNode;
        }
        
        head=prev;
    }
};

int main() {
    LinkedList ll;
    ll.insertathead(1);      
    ll.insertattail(2);
    ll.insertattail(1);
    ll.insertattail(2);
    ll.insertattail(1);
    ll.insertattail(3);
    ll.insertattail(1);

   cout<< ll.deleteoccu(1)<<endl;

   ll.display();

   ll.reverse();

   ll.display();



    



}