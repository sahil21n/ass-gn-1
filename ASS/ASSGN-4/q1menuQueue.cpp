#include<iostream>
#include<stack>

using namespace std;

class queue{
    public:
    int arr[100];
    int front;
    int rear;
    int capacity;

    queue(){
        front=-1;
        rear=-1;
        capacity=100;
    }

    int size(){
        if(front == -1 || front > rear) return 0;
        else return rear-front+1;
    }

    void push_bac(int val){
        if(rear==-1 && rear==front){
            rear++;
            front++;
            arr[rear]=val;
        }
        else if(size()==capacity){
            cout<<"pushing not valid,queue is full"<<endl;
        }
        else{
            rear++;
            arr[rear]=val;
        }
    }

    void pop_front(){
        if(rear==-1 && rear==front){
            cout<<"pop not possible"<<endl;
        }
        else if(front>rear){
            cout<<"pop not possible"<<endl;
        }
        else front++;
    }

    bool Is_Empty(){
        if(rear==-1 && front==rear) return true;
        else return false;
    }

    bool Is_Full(){
        if(size()==capacity) return true;
        else return false;
    }

    void display(){
        if(Is_Empty()){
            cout<<"Queue is empty"<<endl;
            return;
        }
        for(int i=front;i<=rear;i++){
            cout<<arr[i]<<" ";
        }
        cout<<endl;
    }

    int peek(){
        if(Is_Empty()){
            cout << "Queue empty" << endl;
            return -1;
        }
        return arr[front];
    }
};

int main(){
    queue q;
    int choice, val;

    while (true) {
        cout << "\n--- Queue Menu ---\n";
        cout << "1. Enqueue (push_bac)\n";
        cout << "2. Dequeue (pop_front)\n";
        cout << "3. Peek\n";
        cout << "4. Display\n";
        cout << "5. Is Empty?\n";
        cout << "6. Is Full?\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Exiting..." << endl;
            break;
        }

        switch (choice) {
        case 1:
            cout << "Enter value to enqueue: ";
            cin >> val;
            q.push_bac(val);
            break;
        case 2:
            q.pop_front();
            break;
        case 3:
            val = q.peek();
            if (val != -1) cout << "Front element: " << val << endl;
            break;
        case 4:
            q.display();
            break;
        case 5:
            cout << (q.Is_Empty() ? "Queue is empty" : "Queue is not empty") << endl;
            break;
        case 6:
            cout << (q.Is_Full() ? "Queue is full" : "Queue is not full") << endl;
            break;
        default:
            cout << "Invalid choice!" << endl;
        }
    }

    return 0;
}
