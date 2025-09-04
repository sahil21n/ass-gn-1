#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q;

public:
    // push is simple
    void push(int val) {
        q.push(val);
    }

    // pop: rotate until last element is in front, then remove it
    void pop() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        int size = q.size();
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }

        cout << "Popped: " << q.front() << endl;
        q.pop();
    }

    // peek: rotate until last element is in front, get it, then push it back
    int peek() {
        if (q.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        int size = q.size();
        for (int i = 1; i < size; i++) {
            q.push(q.front());
            q.pop();
        }

        int x = q.front(); // last element
        q.pop();
        q.push(x); // put it back

        return x;
    }

    bool empty() {
        return q.empty();
    }
};

int main() {
    MyStack st;
    st.push(10);
    st.push(20);
    st.push(30);

    cout << "Top: " << st.peek() << endl; // 30
    st.pop();                             // Popped: 30
    cout << "Top: " << st.peek() << endl; // 20
}
