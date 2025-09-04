// Write a program interleave the first half of the queue with second half.
// Sample I/P: 4 7 11 20 5 9 Sample O/P: 4 20 7 5 11 9

#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void interleaveQueue(queue<int>& q) {
    int n = q.size();
    if (n % 2 != 0) {
        cout << "Queue size must be even!" << endl;
        return;
    }

    int half = n / 2;
    stack<int> st;

    // Step 1: Push first half into stack
    for (int i = 0; i < half; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back into queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move first half (reversed half) to back of queue
    for (int i = 0; i < half; i++) {
        q.push(q.front());
        q.pop();
    }

    // Step 4: Again take first half into stack
    for (int i = 0; i < half; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 5: Interleave stack and queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();

        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(4);
    q.push(7);
    q.push(11);
    q.push(20);
    q.push(5);
    q.push(9);

    interleaveQueue(q);

    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
