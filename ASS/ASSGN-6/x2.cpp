#include <iostream>
using namespace std;



struct DLLNode {
    int data;
    DLLNode* prev;
    DLLNode* next;
};

DLLNode* removeEvenDLL(DLLNode* head) {

    if (head == NULL) return NULL;

    // Dummy to handle head deletion easily
    DLLNode* dummy = new DLLNode{-1, NULL, head};
    head->prev = dummy;

    DLLNode* temp = dummy;

    while (temp->next != NULL) {
        if (temp->next->data % 2 == 0) {     // even => delete
            DLLNode* del = temp->next;

            temp->next = del->next;
            if (del->next != NULL)
                del->next->prev = temp;

            delete del;
        } else {
            temp = temp->next;
        }
    }

    head = dummy->next;
    if (head != NULL) head->prev = NULL;

    delete dummy;
    return head;
}





struct CSNode {
    int data;
    CSNode* next;
};

CSNode* removeEvenCSLL(CSNode* head) {

    if (head == NULL) return NULL;

    // 1. Find tail (node whose next is head)
    CSNode* tail = head;
    while (tail->next != head) {
        tail = tail->next;
    }

    // 2. Break circular link -> convert to normal SLL
    tail->next = NULL;

    // 3. Use dummy deletion logic for even removal
    CSNode* dummy = new CSNode{-1, head};
    CSNode* temp = dummy;

    while (temp->next != NULL) {
        if (temp->next->data % 2 == 0) {     // even => delete
            CSNode* del = temp->next;
            temp->next = del->next;
            delete del;
        } else {
            temp = temp->next;
        }
    }

    // 4. Update head
    head = dummy->next;
    delete dummy;

    // If all nodes deleted
    if (head == NULL) return NULL;

    // 5. Make circular again
    CSNode* curr = head;
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = head;

    return head;
}



// --------------------------------------------------------------

int main() {
    // You can create DLL and CSLL here and test the functions
    return 0;
}

