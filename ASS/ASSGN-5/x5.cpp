#include<iostream>
using namespace std;

struct Node {
    int coeff;
    int pow;
    Node* next;

    Node(int c, int p) {
        coeff = c;
        pow = p;
        next = NULL;
    }
};

class Solution {
public:
    Node* addPolynomial(Node* p1, Node* p2) {
        if(p1 == NULL) return p2;
        if(p2 == NULL) return p1;

        Node* head = NULL;
        Node* tail = NULL;

        while(p1 != NULL && p2 != NULL){
            Node* temp = NULL;

            if(p1->pow == p2->pow){
                temp = new Node(p1->coeff + p2->coeff, p1->pow);
                p1 = p1->next;
                p2 = p2->next;
            }
            else if(p1->pow > p2->pow){
                temp = new Node(p1->coeff, p1->pow);
                p1 = p1->next;
            }
            else{
                temp = new Node(p2->coeff, p2->pow);
                p2 = p2->next;
            }

            if(head == NULL){
                head = temp;
                tail = temp;
            }
            else{
                tail->next = temp;
                tail = tail->next;
            }
        }

        // Add remaining terms
        while(p1 != NULL){
            tail->next = new Node(p1->coeff, p1->pow);
            tail = tail->next;
            p1 = p1->next;
        }

        while(p2 != NULL){
            tail->next = new Node(p2->coeff, p2->pow);
            tail = tail->next;
            p2 = p2->next;
        }

        return head;
    }

    void display(Node* head){
        Node* temp = head;
        while(temp != NULL){
            cout << temp->coeff << "x^" << temp->pow;
            if(temp->next) cout << " + ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    // First polynomial: 5x^3 + 4x^2 + 2x^0
    Node* p1 = new Node(5, 3);
    p1->next = new Node(4, 2);
    p1->next->next = new Node(2, 0);

    // Second polynomial: 5x^1 + 5x^0
    Node* p2 = new Node(5, 1);
    p2->next = new Node(5, 0);

    Solution s;
    Node* res = s.addPolynomial(p1, p2);

    cout << "Resultant Polynomial: ";
    s.display(res);

    return 0;
}
