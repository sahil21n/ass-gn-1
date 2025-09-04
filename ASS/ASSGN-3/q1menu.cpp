#include<iostream>
using namespace std;

class Stack {
public:
    int arr[5];
    int idx = -1;

    void push(int val){
        if(idx < 4){        // max index = 4
            idx++;
            arr[idx] = val;
            cout << val << " pushed into stack\n";
        }
        else{
            cout << "Stack Overflow\n";
        }
    }

    void pop(){
        if(idx >= 0){
            cout << arr[idx] << " popped from stack\n";
            idx--;
        }
        else{
            cout << "Stack Underflow\n";
        }
    }

    bool IsFull(){
        return (idx == 4);
    }

    bool IsEmpty(){
        return (idx == -1);
    }

    void display(){
        if(IsEmpty()){
            cout << "Stack is empty\n";
            return;
        }
        cout << "Stack elements: ";
        for(int i = 0; i <= idx; i++){
            cout << arr[i] << " ";
        }
        cout << endl;
    }

    int peek(){
        if(!IsEmpty()) 
            return arr[idx];
        else {
            cout << "Stack is empty\n";
            return -1;
        }
    }
};

int main(){
    Stack st;
    int choice, val;

    cout << "\n--- Stack Menu ---\n";
    cout << "1. Push\n";
    cout << "2. Pop\n";
    cout << "3. Peek\n";
    cout << "4. Display\n";
    cout << "5. Check if Empty\n";
    cout << "6. Check if Full\n";
    cout << "0. Exit\n";

    cout << "Enter your choice: ";
    cin >> choice;

    while(choice != 0){   // ✅ while loop
        switch(choice){
            case 1:
                cout << "Enter value to push: ";
                cin >> val;
                st.push(val);
                break;
            case 2:
                st.pop();
                break;
            case 3:
                cout << "Top element: " << st.peek() << endl;
                break;
            case 4:
                st.display();
                break;
            case 5:
                if(st.IsEmpty()) cout << "Stack is empty\n";
                else cout << "Stack is not empty\n";
                break;
            case 6:
                if(st.IsFull()) cout << "Stack is full\n";
                else cout << "Stack is not full\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

        cout << "\nEnter your choice: ";
        cin >> choice;
    }

    cout << "Exiting program...\n";
    return 0;
}
