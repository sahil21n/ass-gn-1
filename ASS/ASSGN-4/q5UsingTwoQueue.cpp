#include <iostream>
#include <queue>
using namespace std;

class MyStack {
    queue<int> q1, q2;

public:
    void push(int val) {
        // Always push to q1
        q1.push(val);
    }

    void pop() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return;
        }

        // Move all except last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        cout << "Popped: " << q1.front() << endl;
        q1.pop();

        // Swap q1 and q2 so q1 always has the elements
        swap(q1, q2);
    }

    int peek() {
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }

        // Move all except last to q2
        while (q1.size() > 1) {
            q2.push(q1.front());
            q1.pop();
        }

        int x = q1.front();
        q1.pop();
        q2.push(x);  // put it back

        swap(q1, q2);
        return x;
    }

    bool empty() {
        return q1.empty();
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
