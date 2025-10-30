#include<iostream>
using namespace std;

class node{
    public:
    int val;
    node* next;
    node* prev;

    node(int val){
        this->val=val;
        next=prev=NULL;
    }


};

class doublyLL{
    public:
    node*head;
    node* tail;
    int size;

    doublyLL() {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void insertathead(int val){
        node* temp=new node(val);
        if(size==0) {
            head=tail=temp;
        }
        else{
            temp->next=head;
            head->prev=temp;
            head=temp;


        }
        size++;
    
    }

    void insertattail(int val){
        node* temp= new node(val);
        if(size==0) head=tail=temp;

        else{
            tail->next=temp;
            temp->prev=tail;//extra
            tail=temp;
        }
        size++;
    }

    void insertatanyidx(int val,int idx){
        

        if(idx==1) insertathead(val);
        else if(idx==size+1) insertattail(val);
        else if(idx>size+1 || idx<1) cout<< "INSERTION NOT POSSIBLE";

        else{
            node* t=new node(val);
            node* temp=head;

            for(int i=1;i<=idx-2;i++){
                temp=temp->next;
            }

            t->next=temp->next;             
            temp->next=t;
            t->prev=temp;//extra
            t->next->prev=t;//extra
            

            size++;
            
        }
    }

    void deleteathead(){

        if(size==0) {

            cout<<"CANNOT BE DELETED AT HEAD SINCE NO HEAD EXISTS";
            return;
        }


        head=head->next;
        if(head!=NULL) head->prev=NULL;//extra
        if(head==NULL) tail=NULL;//exttra
        size--;
        
    }

    void deleteattail(){
        if(size==0)cout<<"CANNOT BE DELETED AT TAIL SINCE NO TAIL EXISTS";

        else if(size==1){
            deleteathead();
        }

        else {
            node* temp=tail->prev;
            temp->next=NULL;
            tail=temp;
            size--;

        }
    }

     void deleteatidx(int idx) {
        if (idx < 1 || idx > size) { 
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
        
        
        temp->next = temp->next->next; 
        temp->next->prev=temp;       //extra
        
        size--;
    }

    

    

    void display(){
        node* temp=head;
        while(temp!=NULL){
            cout<<temp->val<<" ";
            temp=temp->next;
        }
        cout<<endl;
    }

};
int main(){

    doublyLL dll;

    dll.insertattail(10);
    dll.insertattail(20);
    dll.insertattail(30);
    dll.insertattail(40);
    dll.insertattail(50);

    dll.display();

    dll.deleteatidx(3);
    dll.display();
}