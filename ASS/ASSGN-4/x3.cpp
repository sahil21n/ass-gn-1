#include <iostream>
#include <queue>
#include <stack>
using namespace std;

class Solution {
public:
    bool checkSorted(queue<int> q) {
        stack<int> st;
        int expected = 1;
        int n = q.size();

        while (!q.empty()) {
            int front = q.front();
            q.pop();

            // If current element is expected, send to output
            if (front == expected) {
                expected++;
            }
            // Else if top of stack is expected, pop from stack
            else if (!st.empty() && st.top() == expected) {
                st.pop();
                expected++;
                q.push(front);  // put current element back for later check
            }
            // Else push front element to stack
            else {
                st.push(front);
            }
        }

        // Empty remaining stack
        while (!st.empty() && st.top() == expected) {
            st.pop();
            expected++;
        }

        return (expected == n + 1);
    }
};

int main() {
    queue<int> q;
    q.push(5);
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);

    Solution s;
    if (s.checkSorted(q)) cout << "Yes";
    else cout << "No";

    return 0;
}
