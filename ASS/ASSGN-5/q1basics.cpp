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
};

int main() {
    LinkedList ll;
    ll.insertathead(10);
    
    ll.insertattail(20);
    ll.insertattail(30);
    ll.insertattail(40);
    ll.insertattail(50);
    
    cout << "Original list: ";
    ll.display(); // Output: 10 20 30 40 50

    cout << "Deleting at index 3 (value 30): ";
    ll.deleteatidx(3);
    ll.display(); // Output: 10 20 40 50

    cout << "Deleting tail: ";
    ll.deleteattail();
    ll.display(); // Output: 10 20 40

    cout << "Deleting head: ";
    ll.deleteathead();
    ll.display(); // Output: 20 40
    
    cout << "Inserting 99 at index 2: ";
    ll.insertatidx(99, 2);
    ll.display(); // Output: 20 99 40
}
// When 'll' goes out of scope here, the ~LinkedList() destructor
// will be called, freeing all remaining nodes (20, 99, 40).